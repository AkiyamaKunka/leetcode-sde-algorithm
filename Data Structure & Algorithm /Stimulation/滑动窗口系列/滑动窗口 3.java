class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        // https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/submissions/
        int ans = 0;
        int l = 0;
        int r = 0;
        int m = 0;
        HashSet<Character> set = new HashSet<>();
        while(r < s.length()){
            if(set.contains(s.charAt(r)) ){
                if(s.charAt(m) != s.charAt(r)){
                    m = r;
                }
            }else{
                set.clear();
                set.add(s.charAt(m));
                set.add(s.charAt(r));
                l = m;
                m = r;
            }
            if(r - l + 1 > ans) ans = r - l + 1;
            r++;
        }
        return ans;
    }
}