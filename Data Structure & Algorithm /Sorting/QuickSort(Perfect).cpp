#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <sstream>
#include <map>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <vector>
#include <utility>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <cctype>
using namespace std;
#define LOCAL
const int maxn =1000;

int n;
int arr[maxn];

void exch(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void show(){
    for(int i = 0; i < n; i++){
        cout << arr[i];
        if(i != n - 1) cout << " ";
    }
    cout << endl;
}

void quickSort(int begin, int end){
    if(begin > end) return ; // to prevent i - 1 is smaller than begin or i + 1 is bigger than end;
    int piv = arr[end];
    int i = begin;
    int j = end;
    while(i < j) { // if i == j then it quit
        while (i < j && arr[i] <= piv) { // must be arr[i] <= piv, because we wanna find the point that is bigger than piv
            i++;                        // it shuold not be equals to piv, if it equals to piv, then it would stop
        }
        while (i < j && arr[j] >= piv) {
            j--;
        }
        if(i < j) // if i = j, donnot exchange
            exch(i, j);
    }
    //cout << "i is " << arr[i] << " and piv is " << arr[end] << endl;
    exch(i, end);
    quickSort(begin, i - 1);
    quickSort(i + 1, end);
    return ;
}


int main(){
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/algorithm/input.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/algorithm/output.txt", "w", stdout);
#endif
    cin >> n;
    int temp;
    for(int i = 0;i < n; i++){
        cin >> temp;
        arr[i] = temp;
    }
    quickSort(0, n - 1);
    show();

    return 0;
}

