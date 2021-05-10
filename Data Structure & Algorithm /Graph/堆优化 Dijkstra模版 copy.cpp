class Solution {
    // https://leetcode-cn.com/problems/as-far-from-land-as-possible/submissions/
public:
    static constexpr int dx[4] = {0, 1, 0, -1};
    static constexpr int dy[4] = {1, 0, -1, 0};
    static constexpr int INF = int(1E6);
    static constexpr int MAX = 100 + 5;

    class Node{
    public :
        int x;
        int y;
        int v;
        Node(int x, int y, int v):x(x), y(y), v(v){}
        bool operator < (const Node & rhs) const{   // wanna build a minimum heap
            return rhs.v < v;   // remember this way to override operator to compare
        }
    };

    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        int ans = -1;
        priority_queue<Node> q;
        vector<vector<int>> dis(N, vector<int>(N, INF));   // 无需设置vis，优先队列即可保证无重复访问

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++){
                if(grid[i][j]) {         // found land
                    dis[i][j] = 0;
                    Node node(i, j, 0);
                    q.push(node);
                }
            }
        while(!q.empty()){
            Node p = q.top();
            q.pop();
            for (int i = 0; i < 4; i++){
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                int nv = p.v + 1;
                if(!(nx >= 0 && nx < N && ny >= 0 && ny < N)){          // out of boundary
                    continue;
                }
                if(nv < dis[nx][ny]){   // able to set slack
                    dis[nx][ny] = nv;
                    Node node(nx, ny, nv);
                    q.push(node);
                }
            }
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++){
                if(!grid[i][j]){            // found sea
                    ans = max(ans, dis[i][j]);
                }
            }
        return ans == INF ? -1 : ans;
    }
};