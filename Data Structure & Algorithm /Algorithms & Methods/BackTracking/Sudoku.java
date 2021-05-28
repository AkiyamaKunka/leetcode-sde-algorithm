class Solution {
    // https://leetcode-cn.com/problems/sudoku-solver/
    final int n = 9;
    boolean find = false;
    List<HashSet<Character>> set = new ArrayList<>(); // id is i * n + j
    void dfs(int cur, char[][] board){
        if(cur == n * n ){
            find = true;
            return;
        }
        if(cur > n * n || find == true) return;
        int i = cur / n;
        int j = cur % n;
        if(board[i][j] != '.'){
            dfs(cur + 1, board);
        }
        else{
            for(int num = 1; num < 10; ++num){
                char ch = Character.forDigit(num, 10);
                if(isValid(i, j, board, ch)){
                    board[i][j] = ch;
                    set.get(i / 3 * 3 + j / 3).add(ch);
                    dfs(cur + 1, board);
                    if(!find){
                        board[i][j] = '.';
                        set.get(i / 3 * 3 + j / 3).remove(ch);
                    }
                }
            }
        }
    }
    boolean isValid(int y, int x, char[][] board, char ch){
        if(y < 0 || x < 0 || y >= n || x >= n) return false;
        if(set.get(y / 3 * 3 + x / 3).contains(ch)) return false;
        for(int i = 0; i < n; ++i){
            if(ch == board[i][x]) return false;
        }
        for(int j = 0; j < n; ++j){
            if(ch == board[y][j]) return false;
        }
        return true;
    }
    void init(char[][] board){
        for(int i = 0; i < n; ++i){
            set.add(new HashSet<Character>());
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j){
                if(board[i][j] != '.'){
                    set.get(i / 3 * 3 + j / 3).add(board[i][j]);
                }
            }
    }
    public void solveSudoku(char[][] board) {
        init(board);
        dfs(0, board);
    }
}