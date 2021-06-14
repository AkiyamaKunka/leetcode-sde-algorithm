class Solution {
    // https://leetcode-cn.com/problems/permutation-in-string/
    boolean check(int[] raw, int[] win){
        for(int i = 0; i < 26; ++i){
            if(raw[i] != win[i]) return false;
        }

        return true;
    }
    public boolean checkInclusion(String s1, String s2) {
        if(s1.length() > s2.length()) return false;
        int [] raw = new int[26];
        int m = s1.length();
        for(int i = 0; i < m; ++i){
            raw[s1.charAt(i) - 'a']++;
        }
        int [] win = new int[26];
        for(int i = 0; i < m; ++i){
            win[s2.charAt(i) - 'a']++;
        }
        int p = m - 1;
        while(p < s2.length()){
            if(check(raw, win)) return true;
            win[s2.charAt(p - m + 1) - 'a']--;
            p++;
            if(p < s2.length())
                win[s2.charAt(p) - 'a']++;
        }

        return false;
    }
}

