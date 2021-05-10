#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;
#define LOCAL
const int maxn =1000000;
//一道非常炫技的DP https://leetcode-cn.com/problems/get-kth-magic-number-lcci/
class Solution {
public:
    int getKthMagicNumber(int k) {

        vector<int>arr(k + 1);
        arr[0] = 1;
        int p1, p2, p3;
        p1 = p2 = p3 = 0;
        for (int i = 1; i < k; i++){
            arr[i] = min(arr[p1] * 3, min(arr[p2] * 5, arr[p3] * 7));
            if(arr[i] == arr[p1] * 3) p1++;
            if(arr[i] == arr[p2] * 5) p2++;
            if(arr[i] == arr[p3] * 7) p3++;
        }
        return arr[k - 1];
    }
};

int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled5/data_in.txt", "r", stdin);
    //freopen("/Users/robertwong/CLionProjects/untitled5/data_out.txt","w",stdout);
#endif
    Solution sampleHeap;
    cout << "the Fianl Solution is " << sampleHeap.getKthMagicNumber(251);

}
