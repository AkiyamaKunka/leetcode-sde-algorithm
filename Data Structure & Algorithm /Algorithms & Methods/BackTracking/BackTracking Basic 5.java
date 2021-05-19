class Solution {
    //https://leetcode-cn.com/problems/restore-ip-addresses/
    int n;
    List<String> ans = new LinkedList<>();
    boolean isValid(String s, int cur, int step){
        String sub = s.substring(cur, cur + step);
        Integer value = Integer.valueOf(sub);

        if(value < 0 || value > 255) return false;
        if( (step == 3 || step == 2) && s.charAt(cur) == '0' ) return false;
        return true;

    }
    void dfs(int cur, String s, String subAns, int cnt){
        if(cur > s.length() || cnt > 4) return;
        if(cur == s.length() && cnt == 4){
            subAns = subAns.substring(0, subAns.length() - 1);
            ans.add(new String(subAns));
            return;
        }
        for(int i = 1; i < 4; i++){
            if(cur + i <= s.length() && isValid(s, cur, i)){
                subAns += s.substring(cur, cur + i);
                subAns += ".";
                dfs(cur + i, s, subAns, cnt + 1);
                subAns = subAns.substring(0, subAns.length() - i - 1);
            }
        }
    }
    public List<String> restoreIpAddresses(String s) {
        n = s.length();
        String subAns = "";
        dfs(0, s, subAns, 0);
        return ans;
    }
}