class Solution {
    // https://leetcode-cn.com/problems/integer-to-roman/submissions/
    String [] first = new String[] {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; // 1 - 9
    String [] second = new String[] {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; // 10 - 90
    String [] third = new String[] {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};// 100 - 900
    String [] fourth = new String[] {"", "M", "MM", "MMM"}; // 1000 - 3000

    public String intToRoman(int num) {
        String ans = "";
        int d_4 = num / 1000;
        int d_3 = num % 1000 / 100;
        int d_2 = num % 100 / 10;
        int d_1 = num % 10;
        ans += fourth[d_4];
        ans += third[d_3];
        ans += second[d_2];
        ans += first[d_1];
        return ans;
    }
}



class Solution {
    int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    public String intToRoman(int num) {
        StringBuffer s = new StringBuffer();
        for(int i = 0; i < values.length; ++i){
            int value = values[i];
            String str = symbols[i];
            while(num >= value){
                num -= value;
                s.append(str);
            }
            if(num == 0) break;
        }
        return s.toString();
    }
}