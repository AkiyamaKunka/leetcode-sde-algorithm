class Solution {
    //https://leetcode-cn.com/problems/path-with-minimum-effort/
private:
    struct Edge{
        int l;
        int r;
        int v;
        Edge(int _l, int _r, int _v){
            l = _l; r = _r; v = _v;
        }
    };
    struct cmp{
        bool operator()(const Edge& l, const Edge& r){
            return l.v > r.v;
        }
    };

    int * fa;
    int n;
    int row;
    int col;
    priority_queue<Edge, vector<Edge>, cmp> q;

    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void unit(int x, int y){
        fa[find(x)] = find(y);
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        n = row * col;
        fa = new int[n];
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++){
                int id = col * i + j;
                if(i < row - 1){  // vertical edge
                    q.push(Edge(id, id + col, abs(heights[i][j] - heights[i + 1][j])));
                }
                if(j < col - 1){  // horizontal edge
                    q.push(Edge(id, id + 1, abs(heights[i][j] - heights[i][j + 1])));
                }
            }
        int ans = 0;
        while(!q.empty()){
            Edge _t = q.top();
            q.pop();
            unit(_t.l, _t.r);
            if(find(0) == find(col * row - 1)){
                ans = _t.v;
                break;
            }
        }
        return ans;
    }
};