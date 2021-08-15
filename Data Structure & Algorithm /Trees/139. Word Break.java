class Solution {
    List<String> dict;
    boolean ans = false;
    int [] memo;
    public boolean wordBreak(String s, List<String> wordDict) {
        dict = wordDict;
        memo = new int[s.length()];
        insert(s, 0);
        return ans;
    }
    public void insert(String s, int cur_index){
        if(cur_index == s.length()){
            ans = true;
            return;
        }
        if(memo[cur_index] == 1){
            return;
        }
        for(String it: dict){
            int char_len = it.length();
            if(char_len + cur_index <= s.length() && s.substring(cur_index, char_len + cur_index).equals(it)){
                if(cur_index != s.length()) memo[cur_index] = 1;
                insert(s, cur_index + char_len);
            }
        }
    }
}
