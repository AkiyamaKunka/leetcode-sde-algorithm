class Solution {
    //https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/submissions/
    // using hashSet for prevent repetition, very basic, and high efficiency
    void swap(int x, int y, char [] ch){
        char temp = ch[x];
        ch[x] = ch[y];
        ch[y] = temp;
    }

    void backTracking(char [] ch, LinkedList<String> ans, int cur){
        if(cur == ch.length - 1){
            ans.add(String.valueOf(ch));
            return;
        }
        HashSet<Character> mySet = new HashSet<>();
        for(int i = cur; i < ch.length; ++i){
            if(mySet.contains(ch[i])) continue;
            mySet.add(ch[i]);
            swap(i, cur, ch);
            backTracking(ch, ans, cur + 1);
            swap(i, cur, ch);
        }

    }

    public String[] permutation(String s) {
        LinkedList<String> ans = new LinkedList<>();
        char [] ch = s.toCharArray();
        backTracking(ch, ans, 0);
        return ans.toArray(new String[ans.size()]);
    }
}