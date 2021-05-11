class Solution {
    // https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph/submissions/
    int * fa;
    int n;
    int cnt;
    int find(int x){
        if(fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }
    void unit(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx == fy) return;
        fa[fx] = fy;
        cnt--;
    }
    void init(){
        fa = new int[n];
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
        cnt = n;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        this->n = n;
        init();
        for(auto & it: edges){
            unit(it[0], it[1]);
        }
        return cnt;
    }
};