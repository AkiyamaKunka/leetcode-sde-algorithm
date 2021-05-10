class Solution6 {
    // https://leetcode-cn.com/problems/the-maze/

    bool ans;
    int n;
    int m;
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0, -1};
    int desX;
    int desY;

    void dfs(int x, int y, int vis[], vector<vector<int>>& maze){  // the index would be displayed in x * n + y, 1 means visted
        if(ans) return;
        vis[x * n + y] = 1;
        for (int i = 0; i < 4 && ans == false; i++){ // choose one direction
            int nx = x + dx[i];
            int ny = y + dy[i];
            while(isInBoarder(nx, ny, maze) && vis[nx * n + ny] == 0){
                if(nx == desX && ny == desY){
                    ans = true; break;
                }
                nx += dx[i];
                ny += dy[i];
            }
            dfs(nx, ny, vis, maze);
        }



    }
    bool isInBoarder(int x, int y, vector<vector<int>>& maze){
        if(x == -1 || x == m || y == -1 || y == n || maze[x][y] == 1){
            return false;
        }
        return true;
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        ans = false;
        m = maze.size();
        n = maze[0].size();
        desX = destination[0];
        desY = destination[1];
        int * vis = new int[m * n];
        for (int i = 0; i < m * n; i++){
            vis[i] = 0;
        }
        dfs(start[0], start[1], vis, maze);
        return ans;
    }
};