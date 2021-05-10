#include <cstdio>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include <ctime>
#include <sstream>
#include <map>

#include <unordered_set>
#include <unordered_map>



#include <iostream>
using namespace std;
#define LOCAL
class SolutionA {
public:
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0 ,0,-1};
    struct Node {
        int index;
        vector<int> path;
    };

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int sizeWord = beginWord.length();
        int size = wordList.size();

        vector<vector<int>> info(size,vector<int>(size));

        for (int i = 0; i < size; i++){
            for (int k = i+1; k < size; k++) {
                int cnt = 0;
                int j = 0;
                for ( ; j < sizeWord; j++) {
                    if (wordList[i][j] == wordList[k][j]) {
                        cnt++;
                    }
                }
                if(cnt == sizeWord-1)
                    info[i][j] = info[j][i] = 1;
            }
        }
        vector<vector<string>> ans;//最终的答案

        for (int l = 0; l < size; l++){
            int cnt = 0;
            int i = 0;
            for (; i < sizeWord; i++){
                if(beginWord[i]==wordList[l][i])
                    cnt++;
            }
            if(cnt == sizeWord - 1){//找到了图的入口
                queue<Node> wait;
                Node first;
                first.index = i;
                first.path.push_back(i);

                wait.push(first); //把第一个元素推入queue中
                while(!wait.empty()){
                    Node cur = wait.front();
                    vector<int>curPath(cur.path);
                    wait.pop();
                    for (int j = 0; j <size ; j++){
                        if( info[i][j] ){
                            if(!cur.path[j]){
                                continue;
                            }
                            Node newOne;
                            newOne.index = j;
                            curPath.push_back(j);
                            newOne.path = curPath;
                            wait.push(newOne);
                            if(wordList[j] == endWord){
                                for (int k = 0; k <newOne.path.size() ; k++){
                                    ans[ans.size()-1].resize(newOne.path.size());
                                    ans[ans.size()-1][k] = newOne.path[k];
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

const int INF = 1 << 20;

class SolutionB {
private:
    unordered_map<string, int> wordId;
    vector<string> idWord;
    vector<vector<int>> edges;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int id = 0;
        for (const string& word : wordList) {
            if (!wordId.count(word)) {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }
        if (!wordId.count(endWord)) {
            return {};
        }
        if (!wordId.count(beginWord)) {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        edges.resize(idWord.size());
        for (int i = 0; i < idWord.size(); i++) {
            for (int j = i + 1; j < idWord.size(); j++) {
                if (transformCheck(idWord[i], idWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        const int dest = wordId[endWord];
        vector<vector<string>> res;
        queue<vector<int>> q;
        vector<int> cost(id, INF);
        q.push(vector<int>{wordId[beginWord]});
        cost[wordId[beginWord]] = 0;
        while (!q.empty()) {
            vector<int> now = q.front();
            q.pop();
            int last = now.back();
            if (last == dest) {
                vector<string> tmp;
                for (int index : now) {
                    tmp.push_back(idWord[index]);
                }
                res.push_back(tmp);
            } else {
                for (int i = 0; i < edges[last].size(); i++) {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }

    bool transformCheck(const string& str1, const string& str2) {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++) {
            if (str1[i] != str2[i]) {
                ++differences;
            }
        }
        return differences == 1;
    }
};

class SolutionD {
private:
    vector<int>fa;

public:
    int find(int x ){
        if(fa[x] == x)
            return x;
        else{
            fa[x] = find(fa[x]);
            return fa[x];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        fa.resize(26);
        for (int j = 0; j < 26; j++)
            fa[j]=j;
        for (int i = 0; i < equations.size(); i++){
            if(equations[i][1] == '='){
                fa[(int)(equations[i][3]-26)]=(int)(equations[i][0]-26);
            }
        }
        for (int k = 0; k < equations.size(); k++){
            if(equations[k][1] == '!'){
                if(find((int)(equations[k][3]-26)) == find((int)(equations[k][0]-26) ) )
                    return false;
            }
        }
        return true;
    }
};

class Solutionx{

public:
    int dp( int x ,vector<int>& temp){
        if(x == 0)
            return 1;
        else if(x ==1)
            return 1;
        else {
            int temp1,temp2;
            if(temp[x]<26){
                temp1 = dp(x-1,temp) ;
                cout<<temp1;
            } else{
                temp1 = 0;
            }
            if(temp[x-2]*10+temp[x-1] < 26){
                temp2 = dp(x-2,temp) ;
                cout<<temp2;
            } else{
                temp2 = 0;
            }
            return temp1 + temp2;
        }
    }
    int translateNum(int num) {
        vector<int> temp;

        int size;

        while(num != 0){
            temp.push_back(num % 10);
            num = num / 10;
        }
        reverse(temp.begin(),temp.end());
        size = temp.size();
        return dp(size,temp);
    }
};


class SolutionX {
    struct Duo{
        int index;
        int value;
    };
    int binarySearch(int target,vector<int>temp){
        if(temp[temp.size()/2]== target) return temp.size()/2;
        //else if( temp[temp.size()/2] > target)
    }

//排序
// value从0开始枚举
// BS找

public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int tempSum;
        vector<int>ans;
        for (int i = 0; i < arr[arr.size()-1]; i++){
            //二分查找，找到大于value的第一个元素并且返回索引


            // ans.push_back(tempSum + )
        }

    }
    class Solutionsd{
    public:
        int findBestValue(vector<int>& arr, int target) {
            sort(arr.begin(), arr.end()); //排序
            vector<int> presum(arr.size() + 1); //初始每个元素为0
            for (int i = 1; i <= arr.size(); i ++) presum[i] = presum[i - 1] + arr[i - 1]; //前缀和
            int l = 1, r = arr[arr.size() - 1];  //(1,max)
            while (l < r) {
                int mid = l + r >> 1; // 分区间
                getsum(arr, presum, mid) < target ? l =  mid + 1 : r = mid;
            }
            return abs(getsum(arr, presum, l) - target) < abs(getsum(arr, presum, l - 1) - target) ?  l : l - 1;
        }
        int getsum(vector<int>& arr, vector<int>& presum, int value) {
            vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), value); //迭代器
            int sum = presum[iter - arr.begin()] + (arr.end() - iter) * value; //前缀和 + value和
            return sum;
        }
    };

};

class Solutionfdsa{
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }

        int r = *max_element(arr.begin(), arr.end());
        int ans = 0, diff = target;
        for (int i = 1; i <= r; ++i) {
            auto iter = lower_bound(arr.begin(), arr.end(), i);
            int cur = prefix[iter - arr.begin()] + (arr.end() - iter) * i;
            if (abs(cur - target) < diff) {
                ans = i;
                diff = abs(cur - target);
            }
        }
        return ans;
    }
};




void quick_sort(int *a, int start, int end){
    if(start >= end) return;
    int left = start;
    int right = end;
    int pivot = a[(end + start) / 2];
    while(left<=right) {
        while (left <= right && a[left] < pivot)
            left++;
        while (left <= right && a[right] > pivot)
            right--;
        if (left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    quick_sort(a,start,right);
    quick_sort(a,left,end);
}

int getMaxDigit(int a[], int n){
    int tempMax = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > tempMax)
            tempMax = a[i];
    }

    int dig = 1;
    while(tempMax / 10 != 0){
        tempMax /= 10;
        dig++;
    }
    return dig;
}

int getNum(int num, int curDig){
    for (int i = 1; i < curDig; i++){
        num /= 10;
    }
    return num % 10;
}



void radixsort(int data[], int n) {
    int d = getMaxDigit(data, n);
    int *tmp = new int[n];
    int *count = new int[10];
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) {
        for (j = 0; j < 10; j++)
            count[j] = 0;
        for (j = 0; j < n; j++) {
            k = (data[j] / radix) % 10;
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j];
        for (j = n - 1; j >= 0; j--) {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }


        for (j = 0; j < n; j++)
            data[j] = tmp[j];
        radix = radix * 10;

        // print here
        for (int l = 0; l < n; l++) {
            cout << tmp[l];
            if (l != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}

class Solution {

private:
    int calcu(char sym, float num1, float num2){
        cout << "the opr is " << sym << " and the number is " << num1 << " " << num2 << endl;
        if(sym == '*') return num1 * num2;
        if(sym == '/') return num2 / num1;
        if(sym == '+') return num1 + num2;
        if(sym == '-') return num2 - num1;
    }

public:

    stack<char> symbo;
    stack<float> num;

};


int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled5/data_in.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/untitled5/data_out.txt","w",stdout);
#endif



    return 0;
}
