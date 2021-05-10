class Solution {

    // https://leetcode-cn.com/problems/as-far-from-land-as-possible/

    // O(n^4)算法不太好 暴力BFS
public:
    static constexpr int dx[4] = {0, 1, 0, -1};
    static constexpr int dy[4] = {1, 0, -1, 0};
    static constexpr int MAX = 100 + 5;
public:
    class Node{
    public:
        int x;
        int y;
        int step;
        Node(int x, int y, int step){
            this->x = x;
            this->y = y;
            this->step = step;
        }
    };

    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        int ans = -1;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++){
                if(!grid[i][j]){
                    // bfs it
                    queue<Node>q;
                    Node node(i, j, 0);
                    q.push(node);
                    bool touch [MAX][MAX];
                    memset(touch, 0, sizeof touch);
                    bool foundLand = false;
                    touch[i][j] = true;

                    while(!foundLand && !q.empty()){            // go into bfs
                        Node p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++){ // search surroundings
                            int nx = p.x + dx[k];
                            int ny = p.y + dy[k];
                            int ns = p.step + 1;
                            if( !(nx >= 0 && nx < N && ny >= 0 && ny < N))   // out of boundary
                                continue;
                            if(!touch[nx][ny]){ // untouched here
                                touch[nx][ny] = true;
                                if(grid[nx][ny]){ // found land
                                    foundLand = true;
                                    if(ns > ans)
                                        ans = ns;
                                    break;
                                }else{ // sea
                                    Node next(nx, ny ,ns);
                                    q.push(next);
                                }
                            }
                        }
                    }
                }
            }
        return ans;
    }
};
