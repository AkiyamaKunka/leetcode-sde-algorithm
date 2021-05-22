class Solution {
    //https://leetcode-cn.com/problems/eight-queens-lcci/submissions/
    List<List<String>> ans = new LinkedList<>();
    int N;

    boolean judge(int y, int x, List<char[]> sub){
        for(int i = 0; i < N; ++i){ // search vertical chess
            if(i == y) continue;
            if(sub.get(i)[x] == 'Q') return false;
        }
        int b_1 = y - x; // y = x + b is the function of one diagonal
        for(int i = b_1, j = 0; i < N && j < N; ++i, ++j){
            if(i == y && j == x || j < 0 || i < 0) continue;
            if(sub.get(i)[j] == 'Q') return false;
        }
        int b_2 = y + x ; // y = -x + b
        for(int i = 0, j = b_2; i < N && j >= 0; ++i, --j){
            if(i == y && j == x || j >= N) continue;
            if(sub.get(i)[j] == 'Q') return false;
        }
        return true;
    }

    void dfs(int y, List<char[]> sub){
        if(y == N){
            List<String> pre_ans = new LinkedList<>();
            for(int i = 0; i < N; ++i){
                String s = "";
                for(int j = 0; j < N; ++j){
                    s += sub.get(i)[j];
                }
                pre_ans.add(new String(s));
            }

            ans.add(new LinkedList(pre_ans)); // not know now
            return;
        }

        for(int j = 0; j < N; ++j){
            if(judge(y, j, sub)){
                sub.get(y)[j] = 'Q';
                dfs(y + 1, sub);
                sub.get(y)[j] = '.';
            }

        }

    }
    public List<List<String>> solveNQueens(int n) {
        N = n;
        List<char[]> sub = new LinkedList<>();
        for(int i = 0; i < n; ++i){
            char[] t = new char[n];
            for(int j = 0; j < n; ++j){
                t[j] = '.';
            }
            sub.add(t);
        }
        dfs(0, sub);
        return ans;
    }
}