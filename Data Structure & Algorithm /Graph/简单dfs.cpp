class Solution {
    // https://leetcode-cn.com/problems/surrounded-regions/
private:
    int n;
    int m;
    const int dx[4] = {0, 1, -1 ,0};
    const int dy[4] = {1, 0, 0, -1};
    bool isInBoard(int y, int x){
        return 0 <= y && y < n && 0 <= x && x < m;
    }
    void dfs(int y, int x, vector<vector<char>>& board) {
        if(board[y][x] != 'O') return;
        board[y][x] = 'A';
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(isInBoard(ny, nx)
               && board[ny][nx] == 'O'){
                dfs(ny, nx, board);
            }
        }
    }

public:

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < m; i++){
            dfs(0, i, board);
            dfs(n - 1, i, board);
        }
        for (int i = 0; i < n; i++){
            dfs(i, 0, board);
            dfs(i, m - 1, board);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                board[i][j] = (board[i][j] == 'A' ? 'O' : 'X');
            }

    }
};