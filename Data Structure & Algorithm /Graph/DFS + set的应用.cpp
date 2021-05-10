


class Solution {
// https://leetcode-cn.com/problems/route-between-nodes-lcci/
// 这道题主要涉及了重复边的排除，所以用set来做比较好
// set中的全部元素均为不重复元素，而且是用RBT从低到高排列的
    set<int> edge[100010];
    int vis[100010];
    int N;
    int S;
    int T;
    bool find;
    void dfs(int p){
        vis[p] = 1;  // set point on map is touched
        for (auto & end : edge[p]){
            if(find)
                return;
            if(end == T){
                find = true;
            }else if(!vis[end]){
                dfs(end);
            }
        }
    }

public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        N = n;
        find = false;
        S = start;
        T = target;
        for (int i = 0; i < graph.size(); i++){
            int a = graph[i][0];
            int b = graph[i][1];
            edge[a].insert(b);
        }
        dfs(S);
        return find;
    }
};
