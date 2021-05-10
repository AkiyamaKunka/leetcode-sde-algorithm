#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <time.h>
using namespace std;
#define LOCAL
const int maxn =1000000;

class BM{

private:
    vector<int>GSMap;
    string raw;
    string cp;
    vector<int>ans;
public:
    BM(string & raw, string & cp){
        this->raw = raw;
        this->cp = cp;
        GSMap = vector<int>(cp.length(), -1); // we store the repeated location which starts at 0
    }
    void getGSMap(){
        for (int l = 1; l < cp.length(); l++) { // search size of repeated string from 1 to cp.length - 1
            int matchedLength = 0;
            for (int i = cp.length() - 2; i >= 0; i--) { // start from the last character
                if (cp[cp.length() - 1 - matchedLength] == cp[i]) {
                    matchedLength++;
                } else {
                    i += matchedLength;
                    matchedLength = 0;
                    continue;
                }
                if (matchedLength == l) {
                    GSMap[cp.length() - l] = i;
                    break; // store the location
                }
            }
        }
    }
    void showGSMap(){
        for (int i = 0; i < GSMap.size(); i++)
            cout << GSMap[i] << " ";
        cout << endl;
    }
    void solve(){
        int i = cp.length() - 1; // point at cp head position in raw
        int j = cp.length() - 1; // point at cp from the last element

        while(i < raw.length()){
            while(j >= 0){
                int BCmove = 0;
                int GSmove = 0;
                if(cp[j] == raw[i - (cp.length() - 1 - j)]) {
                    j--;
                    if(j == -1) { // whole string matched

                        ans.push_back(i - cp.length() + 1); // store the ans (pushing the index of the head in the array)
                        //i += cp.length();
                        i++;
                        j = cp.length() - 1;
                        break;
                    }
                }
                else { // get a bad char
                    char badChar = raw[i - (cp.length() - 1 - j)]; // here we implement BC
                    int pos1 = -1;
                    for (int k = cp.length() - 1; k >= 0; k--){
                        if(cp[k] == badChar) {
                            pos1 = k;
                            break;
                        }
                    }
                    BCmove = j - pos1;
                    if(j != cp.length() - 1) GSmove = j + 1 - GSMap[j + 1]; // not the head
                    i += (BCmove > GSmove ? BCmove : GSmove);
                    j = cp.length() - 1;
                    break;
                }
            }
        }
    }
    void showAns(){
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
};


class KMP{
private:
    vector<int>next;
    vector<int>ans;
public:

    KMP(string &cp){
        next = vector<int>(cp.length());
        nextUpdate(cp);
    }

    void nextUpdate(string &cp){

        for (int i = 0; i < next.size(); i++){
            if(i == 0) next[0] = 0;// the condition for the first element
            else if(cp[i] == cp[next[i - 1]]) next[i] = next[i - 1] + 1;
            else{
                for (int j = next[next[i - 1] - 1]; j >= 0 ; j = next[j - 1]) {
                    if (cp[i] == cp[j]) {
                        next[i] = j + 1;
                        break;
                    }
                    if (j == 0) {
                        if (cp[i] == cp[0]) next[i] = 1;
                        break;
                    }
                }
            }
        }
    }

    void showAns(){
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] - 1 << " ";
    }

    void solve(string &raw, string &cp){
        int i = 0; // cp's distance moved
        int j = 0; // compare element start from cp
        while(i <= raw.size() - cp.size()){
            if(raw[i + j] != cp[j]) {
                if(j > 0) {
                    i += j - next[j - 1];
                    j = next[j - 1];// move the index of raw
                }
                else i++;
            } else{
                j++; // matched, so we move j on cp
                if(j == cp.size()){
                    ans.push_back(i + 1);  // store the answer
                    if(j > 1) i += j - next[j - 1];
                    else i++;
                    j = 0;
                }
            }
        }
    }
};

int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled5/data_in.txt", "r", stdin);
    //freopen("/Users/robertwong/CLionProjects/untitled5/data_out.txt","w",stdout);
#endif
    clock_t tStart1 = clock();
    string raw, cp;
    cin >> raw >> cp;
    BM BMsample(raw, cp);

    BMsample.getGSMap();
    //sample.showGSMap();
    BMsample.solve();
    //BMsample.showAns();
    printf("BM Time taken: %.2fs\n", (double)(clock() - tStart1)/CLOCKS_PER_SEC);


    clock_t tStart2 = clock();
    KMP KMPsample(cp);
    KMPsample.solve(raw, cp);
    //KMPsample.showAns();
    printf("KMP Time taken: %.2fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);

    /* Do your stuff here */

    return 0;
}
