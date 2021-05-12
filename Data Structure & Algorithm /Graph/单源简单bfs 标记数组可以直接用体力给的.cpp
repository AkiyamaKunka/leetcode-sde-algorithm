class Solution {
// https://leetcode-cn.com/submissions/detail/176938431/
public:
    int getFood(vector<vector<char>>& grid) {
        int sx = -1;
        int sy = -1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '*'){
                    sy = i;
                    sx = j;
                }
        int dis = 0;
        queue<pair<int, int>>q;
        grid[sy][sx] = 'X';
        q.push({sx, sy});
        while(!q.empty()){
            dis++;
            int cnt = q.size();
            while(cnt--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[ny][nx] == 'X' ) continue;
                    if(grid[ny][nx] == '#') return dis;
                    pair<int, int> next(nx, ny);
                    q.push({nx, ny});
                    grid[ny][nx] = 'X';
                }
            }
        }
        return -1;
    }
};