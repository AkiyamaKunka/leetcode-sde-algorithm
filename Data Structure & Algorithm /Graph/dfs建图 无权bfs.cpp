// class GridMaster {
//     public:
//         bool canMove(char direction);
//         void move(char direction);
//         bool isTarget();
//     };


class Solution {
    //https://leetcode-cn.com/problems/shortest-path-in-a-hidden-grid/
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    char nd[4] = {'U', 'D', 'L', 'R'};
    char anti_nd[4] = {'D', 'U', 'R', 'L'};
    bool map[1000][1000] = {false}; // 0 means blocked, 1 means cleared
    int tx;
    int ty;
    bool find = false;

public:
    void dfs(int x, int y, GridMaster& master){
        if(map[x][y]) return;
        map[x][y] = true;
        if(master.isTarget()){
            tx = x;
            ty = y;
            find = true;
        }
        for(int i = 0; i < 4; i++){
            if(master.canMove(nd[i])){
                master.move(nd[i]);
                dfs(x + dx[i], y + dy[i], master);
                master.move(anti_nd[i]);
            }
        }
    }

    int findShortestPath(GridMaster &master) {
        if(master.isTarget()) return 0;
        dfs(500, 500, master);
        if(!find) return -1;

        queue<pair<int, int>>q;
        int ans = 0;
        q.push({500, 500});

        bool vis[1000][1000]= {false};
        while(!q.empty()){
            ans++;
            int cnt = q.size();
            while (cnt--) {
                pair<int, int> node = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nx = node.first + dx[i];
                    int ny = node.second + dy[i];
                    if(nx < 0 || ny < 0 || nx >= 1000 || ny >= 1000 || !map[nx][ny] || vis[nx][ny]) continue;
                    if(nx == tx && ny == ty){
                        return ans;
                    }
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }
};