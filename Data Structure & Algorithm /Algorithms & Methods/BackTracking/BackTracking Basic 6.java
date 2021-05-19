class Solution {
    // https://leetcode-cn.com/problems/word-search/solution/
    // should pay attention to vis set 1 and set 0 when do backtraking
    boolean found = false;
    int m;
    int n;
    int [] dx = {0, 1, -1, 0};
    int [] dy = {1, 0, 0, -1};
    boolean inBoard(int x, int y, int[][] vis){
        if(x < 0 || y < 0 || y >= m || x >= n || vis[y][x] == 1) return false;
        return true;
    }
    void dfs(int x, int y, int[][] vis, char[][] board, int cur, String word){
        if(found == true || cur >= word.length() || inBoard(x, y, vis) == false) return;

        //System.out.println("y is " + y + " x is " + x + " cur is " + cur);

        if(board[y][x] == word.charAt(cur)){
            //System.out.println("found char " + word.charAt(cur));
            vis[y][x] = 1;
            if(cur == word.length() - 1){
                found = true;
                return;
            }
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                //System.out.println("ny is " + ny + " nx is " + nx + " cur is " + (cur + 1));
                //if(ny == 1 && nx == 0) System.out.println(vis[ny][nx]);
                dfs(nx, ny, vis, board, cur + 1, word);
            }
            vis[y][x] = 0;
        }
    }
    public boolean exist(char[][] board, String word) {
        m = board.length;
        n = board[0].length;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(board[i][j] == word.charAt(0)){
                    int [][] vis = new int[m][n];
                    dfs(j, i, vis, board, 0, word);
                }
        return found;
    }
}