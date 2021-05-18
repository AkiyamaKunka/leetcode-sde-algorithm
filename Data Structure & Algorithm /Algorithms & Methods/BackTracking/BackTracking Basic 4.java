class Solution {
    /https://leetcode-cn.com/problems/generate-parentheses/submissions/
    int N;
    List<String> ans = new LinkedList<>();
    void backTracking(int l, int r, int cur, String s){
        if(cur == N * 2){
            ans.add(s);
            return;
        }
        boolean isLeft = false;
        boolean isRight = false;
        if(!isLeft && l < N){
            s += "(";
            isLeft = true;
            backTracking(l + 1, r, cur + 1, s);
            s = s.substring(0, s.length() - 1);
        }
        if(!isRight && r < N && r < l){
            s += ")";
            isRight = true;
            backTracking(l, r + 1, cur + 1, s);
            s = s.substring(0, s.length() - 1);
        }
    }

    public List<String> generateParenthesis(int n) {
        N = n;
        String s = "";
        backTracking(0, 0, 0, s);
        return ans;
    }
}