#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
//#define LOCAL
const int maxn =1000000;
int mat[100][100];

int combinat(int m, int n) {
    int i, j;
    if (n == 0 || m == n)
        return 1;
    for (j = 0; j <= n; j++) {
        mat[j][j] = 1;
        for (i = j + 1; i <= m; i++) {
            if (j == 0)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
        } // calculate Cmn
    }
    return mat[m][n];
}

void bigNum(vector<int> &arr, int snum){
    if(!arr.empty()) {              // the number which waits for calculation already in the vector
        vector<int> temp;
        while (snum > 0) {
            int t = snum % 10;
            temp.push_back(t);
            snum = snum / 10;
        }
        vector<int> ans(arr.size());

        for (int i = 0; i < temp.size(); i++)
            for (int j = 0; j < arr.size(); j++)
                if(j + i < ans.size())
                    ans[j + i] += temp[i] * arr[j];
                else
                    ans.push_back(temp[i] * arr[j]);

        for (int t = 0; t < ans.size(); t++) {
            if (ans[t] >= 10)                           // 2 digit convert to next digit
                if (t + 1 < ans.size())                  // not the last digit
                    ans[t + 1] += ans[t] / 10;
                else
                    ans.push_back(ans[t] / 10);

            ans[t] = ans[t] % 10;
        }

        arr = ans; // pass the answer to the raw array

    }else{  // the first calculation
        while (snum > 0) {
            int t = snum % 10;
            arr.push_back(t);
            snum = snum / 10;
        }
    }
}

void myPow(int a, int n, vector<int> &ans){
    int res = 0;
    for (int i = 0; i < n; i++)
        bigNum(ans, a);
}

void myPrint(vector<int> &ans){
    if(ans.size() != 1)
        for (int i = ans.size() - 1; i >= 0 ; i--)
            cout<< ans[i];
    else{
        if(ans[0] != 1)
            cout << ans[0];
    }
}

void symbol(int a, int b, int i, int n){
    int j1 = 1;
    int j2 = 1;
    if(a < 0 && (n - i) % 2 == 1)
        j1 = -1;
    if(b < 0 && i % 2 == 1)
        j2 = -1;
    if( j1 * j2 == -1)
        cout << '-';
    else if(i > 0)
        cout << '+';
}




class Node{

public:
    int val;
    Node * previous;
    Node * next;

    Node(int x){
        val = x;
    }
};

class MyChain{
    Node * head;    // the real head and end for a chain
    Node * end;
    Node * p;

    MyChain(vector<int> arr){

        head->next = end;
        end->previous = head;
        p = head;

        for (int i = 0; i < arr.size(); i++){
            p->val = arr[i];

        }
    }
};

int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled5/data_in.txt", "r", stdin);
    //freopen("/Users/robertwong/CLionProjects/untitled5/data_out.txt","w",stdout);
#endif
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 0; i < n + 1; i++){
        vector<int>ans;
        myPow(abs(a), n - i, ans);
        myPow(abs(b), i, ans);
        bigNum(ans, combinat(n, i));
        //int index = combinat(n, i) * pow(a, n - i) * pow(b, i);
        symbol(a, b, i, n);
        myPrint(ans);
        if(i < n){
            cout << 'x';
            if(i < n - 1)
                cout << '^' << n - i;
        }
        if(i > 0){
            cout << 'y';
            if( i > 1)
                cout << '^' << i;
        }
    }
    return 0;
}
