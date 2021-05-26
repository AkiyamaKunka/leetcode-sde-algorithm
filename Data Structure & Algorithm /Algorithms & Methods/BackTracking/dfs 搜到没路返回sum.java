class Solution {
    // https://leetcode-cn.com/problems/path-with-maximum-gold/submissions/
    int ans, M, N;
    int[][] vis;
    int [] dx = {1, -1, 0, 0};
    int [] dy = {0, 0, 1, -1};
    boolean isValid(int y, int x){
        if(x < 0 || y < 0 || y >= M || x >= N || vis[y][x] == 0) return false;
        return true;
    }
    void dfs(int y, int x, int sum, int[][]grid){
        vis[y][x] = 0;
        int cnt = 0;
        sum += grid[y][x];
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(ny, nx))
                dfs(ny, nx, sum, grid);
            else
                cnt++;
        }
        if(cnt == 4 && sum > ans)
            ans = sum;
        vis[y][x] = 1;
    }

    public int getMaximumGold(int[][] grid) {
        M = grid.length;
        N = grid[0].length;
        vis = new int[M][N];
        ans = 1;
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j){
                if(grid[i][j] == 0)
                    vis[i][j] = 0; // 0 means unable to visit
                else
                    vis[i][j] = 1;
            }
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                if(isValid(i, j))
                    dfs(i, j, 0, grid);
        return ans;
    }
}