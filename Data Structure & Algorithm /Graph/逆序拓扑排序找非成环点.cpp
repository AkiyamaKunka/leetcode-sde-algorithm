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
#include <list>
using namespace std;
#define LOCAL
#define INF 10000000
#define MAX 10000
const int maxn = 200;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        https://leetcode-cn.com/problems/find-eventual-safe-states/
        // 逆向拓扑排序
        // 记录出度
        // 拓扑排序经常用来判断有没有环
        int n = graph.size();
        vector<vector<int>> edge(n, vector<int>(0));
        // 找到index位置被指的全部点

        vector<int> od(n, 0);
        for (int i = 0; i < n; i++){
            od[i] = graph[i].size();
            for (int j = 0; j < graph[i].size(); j++) {
                edge[graph[i][j]].push_back(i);
            }
        }
        queue<int> q;
        vector<int>ans;

        for (int i = 0; i < n; i++){
            if(!od[i])
                q.push(i);
        }
        while(!q.empty()){
            int p = q.front();
            ans.push_back(p);
            q.pop();
            for (int i = 0; i < edge[p].size(); i++){
                od[edge[p][i]]--;
                if(!od[edge[p][i]])
                    q.push(edge[p][i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};