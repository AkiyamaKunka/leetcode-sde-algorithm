class Solution {
    // https://leetcode-cn.com/problems/optimize-water-distribution-in-a-village/submissions/
    // 这道题的精华在于选一个水源，建立和所有node的连接。既满足水库必须 > 0的条件，又将建立水库的消耗和建立管道的权值同化，用Kruskal解决
    int * fa;
    void init(int n){
        fa = new int[n + 1];
        for(int i = 0; i < n + 1; i++){
            fa[i] = i;
        }
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void unit(int x, int y){
        fa[find(x)] = find(y);
    }
    class Edge{
    public:
        int x;
        int y;
        int v;
        Edge(int _x, int _y, int _v ){
            x = _x;
            y = _y;
            v = _v;
        }
    };
    struct Cmp_Edge{
        bool operator()(Edge & l, Edge & r){
            return l.v > r.v; // decending
        }
    };

public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        init(n);
        priority_queue<Edge, vector<Edge>, Cmp_Edge > edges;
        for(auto & it : pipes){
            Edge edge = Edge(it[0], it[1], it[2]);
            edges.push(edge);
        }
        for(int i = 0; i < wells.size(); i++){
            Edge e = Edge(0, i + 1, wells[i]);
            edges.push(e);
        }
        int cnt = n;
        int ans = 0;
        while(cnt){
            Edge e = edges.top();
            edges.pop();
            int fx = find(e.x);
            int fy = find(e.y);
            if(fx != fy){
                unit(fx, fy);
                ans += e.v;
                cnt--;
            }
        }
        return ans;

    }
};