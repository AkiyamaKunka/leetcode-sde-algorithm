class Solution {
    // https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
    List<String> chs = new LinkedList<>();
    List<Integer> select = new LinkedList<>();
    List<String> ans = new LinkedList<>();
    int n;
    void init(){
        chs.add("abc");
        chs.add("def");
        chs.add("ghi");
        chs.add("jkl");
        chs.add("mno");
        chs.add("pqrs");
        chs.add("tuv");
        chs.add("wxyz");
    }
    void dfs(int cur, String s){
        if(cur == n){
            ans.add(new String(s));
            return;
        }
        int id = select.get(cur);
        String _s = chs.get(id - 2);
        for(int i = 0; i < _s.length(); ++i){
            s += _s.charAt(i);
            dfs(cur + 1, s);
            s = s.substring(0, s.length() - 1);
        }
    }
    public List<String> letterCombinations(String digits) {
        init();
        n = digits.length();
        for(int i = 0; i < n; ++i){
            select.add(Character.getNumericValue(digits.charAt(i)));
        }
        String s = "";
        if(!digits.equals(""))
            dfs(0, s);
        return ans;
    }
}