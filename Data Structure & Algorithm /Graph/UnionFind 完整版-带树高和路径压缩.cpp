class Solution3 {

    // complete version of unionFind
    // https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/submissions/
    int cc;
    int * fa;
    int * sz;
    int find(int x){
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void unit(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx == fy)
            return;
        if(sz[fx] > sz[fy]){
            fa[fy] = fx;
            sz[fx] += sz[fy];
        }else{
            fa[fx] = fy;
            sz[fy] += sz[fx];
        }
        cc--;
    }
    void initUF(int n){
        cc = n;
        fa = new int[cc];
        sz = new int[cc];
        for (int i = 0; i < n; i++){
            fa[i] = i;
            sz[i] = 1;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        initUF(n);
        for (int i = 0; i < connections.size(); i++){
            unit(connections[i][0], connections[i][1]);
        }
        return cc - 1;
    }
};