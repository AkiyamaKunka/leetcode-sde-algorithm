#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <unordered_set>

using namespace std;
//#define LOCAL
const int maxn = 20000007;

int interval;
int num[maxn];
int n;
int minNum, maxNum;
int leftEdge[maxn + 1000000];
int rightEdge[maxn + 1000000];

int  seed  ;
int rand(){ return((( seed   =  seed   * 214013L + 2531011L) >> 16) & 0x7fff); }
int rand32(){
    return ((rand() << 16) + (rand() << 1) + rand() % 2);
}

long long int myHashMap(long long int x){
    return (x - minNum) / interval;
}

int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled5/data_in.txt", "r", stdin);
    //freopen("/Users/robertwong/CLionProjects/untitled5/data_out.txt","w",stdout);
#endif

    cin >> n >> seed;

    for (int i = 1; i < n + 1; i++){
        num[i] = rand32();
        if(i == 1)
            minNum = maxNum = num[i];
        else {
            minNum = min(num[i], minNum);
            maxNum = max(num[i], maxNum);
        }
    }

    interval = (maxNum - minNum) / (n - 1); // initialization
    for (int i = 0; i < maxn; i++) {
        leftEdge[i] = maxNum + 1;
        rightEdge[i] = -1;
    }
    for (int i = 1; i < n + 1; i++){
        int bucket = myHashMap(num[i]);
        leftEdge[bucket] = min(leftEdge[bucket], num[i]);
        rightEdge[bucket] = max(rightEdge[bucket], num[i]);
    }

    int ans = 0, end = -1;
    for(int i = 0; i < maxn + 1000000; i++) // give the answer
    {
        if(leftEdge[i] <= maxNum)
        {
            if(end != -1) ans = max(ans, leftEdge[i]-rightEdge[end]);
            end = i;
        }
    }
    cout << ans << endl;
    return 0;
}


