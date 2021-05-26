class Solution {
    // with optimization
    // https://leetcode-cn.com/problems/n-queens/submissions/
    List<List<String>> ans = new ArrayList<>();
    int N;
    List<String> chsToString(char[][] chs){
        List<String> map = new ArrayList<>();
        for(char[] it : chs)
            map.add(String.copyValueOf(it));
        return map;
    }
    boolean isValid(int x, int y, char[][] chs){
        for(int i = 0; i < x; ++i) // search row
            if(chs[i][y] == 'Q') return false;
        for(int i = x, j = y; i >= 0 && j >= 0; --i, --j)  // y = x + b
            if(chs[i][j] == 'Q') return false;
        for(int i = x, j = y; i >= 0 && j < N; --i, ++j) // y = -x + b
            if(chs[i][j] == 'Q') return false;
        return true;
    }
    void dfs(int cur, char[][] chs){
        if(cur == N){
            ans.add(chsToString(chs));
            return;
        }
        for(int j = 0; j < N; ++j){
            if(isValid(cur, j, chs)){
                chs[cur][j] = 'Q';
                dfs(cur + 1, chs);
                chs[cur][j] = '.';
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        N = n;
        char[][] chs = new char[n][n];
        for(char[] it : chs)
            Arrays.fill(it, '.');
        dfs(0, chs);
        return ans;
    }
}