class Solution {
    // https://leetcode-cn.com/problems/roman-to-integer/submissions/
    int getNum(char ch){
        if(ch == 'I' ) return 1;
        else if(ch == 'V') return 5;
        else if(ch == 'X') return 10;
        else if(ch == 'L') return 50;
        else if(ch == 'C') return 100;
        else if(ch == 'D') return 500;
        else if(ch == 'M') return 1000;
        else return -1;
    }

    public int romanToInt(String s) {
        int ans = 0;
        for(int i = 0; i < s.length(); ++i){
            int num = getNum(s.charAt(i));
            if(i + 1 < s.length() && getNum(s.charAt(i + 1)) > num ){
                ans -= num;
            }else{
                ans += num;
            }
        }
        return ans;
    }
}