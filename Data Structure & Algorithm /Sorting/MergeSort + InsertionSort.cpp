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
const int maxn =103;

int n;
int raw[maxn];
int arr[maxn];

void reloadArr(){
    for (int i = 0; i < n; i++)
        arr[i] = raw[i];
}

void input(){
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        raw[i] = temp;
    }
    reloadArr();
}

void show(){
    for (int i = 0; i < n; i++){
        cout << arr[i];
        if(i != n - 1) cout << " ";
    }
    cout << endl;
}

void insertSort(int index = 1){
    if(index > n - 1) return ;
    int key = arr[index]; // insert key to array from 0 to 0 ~ index - 1
    int i = index - 1;
    while(i > -1 && arr[i] > key){
        arr[i + 1] = arr[i]; // move
        i--;
    }
    arr[i + 1] = key; // insertion complete
    insertSort(index + 1);
}

void merge(int begin, int mid, int end){
    int i = begin;
    int j = mid + 1;
    vector<int>tempAns;
    while(i < mid + 1 || j < end + 1) {
        if (i < mid + 1 && arr[i] <= arr[j] || j >= end + 1) {
            tempAns.push_back(arr[i]);
            i++;
        }
        if (j < end + 1 && arr[i] > arr[j] || i >= mid + 1) {
            tempAns.push_back(arr[j]);
            j++;
        }
    }
    for (int k = 0; k < tempAns.size(); k++)
        arr[begin + k] = tempAns[k];
}

void MergeSortDivide(int begin, int end){ // a more elegant way for mergeSort
    if(begin < end){
        int mid = (begin + end) / 2;
        divide(begin, mid);
        divide(mid + 1, end);
        merge(begin, mid, end);
        show();
    }
}

void mergeSortIterate(){ // here I used iteration, but divide and conquer is more beautiful, see divide function above
    for(int k = 0; pow(2, k) <= n; k++) {
        int l = pow(2, k);
        for (int i = 0; i < n; i += 2 * l){
            merge(i, i + l - 1, min(i + 2 * l - 1, n - 1));
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/algorithm/input.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/algorithm/output.txt", "w", stdout);
#endif
    input();
    insertSort();
    reloadArr();
    mergeSortIterate();
    return 0;
}
