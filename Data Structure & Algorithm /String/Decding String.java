class Solution {
    // https://leetcode-cn.com/problems/decode-string/
    String solve (String s){
        LinkedList<String> ls = new LinkedList<>();
        for(int i = 0; i < s.length(); ++i){
            if(s.charAt(i) == '['){
                int times = 0;
                int j = i;
                int j_cnt = 0;
                while(j != 0 && Character.isDigit(s.charAt(j - 1)) ){
                    times += Math.pow(10, j_cnt) * Character.getNumericValue(s.charAt(j - 1));
                    j--;
                    j_cnt++;
                }
                if(times == 0) times = 1;
                int begin = i + 1;
                int cnt = 0;
                while(i < s.length()){
                    i++;
                    if(s.charAt(i) == '[') cnt++;
                    if(s.charAt(i) == ']'){
                        if(cnt == 0){
                            int end = i;
                            String sub = solve(s.substring(begin, end));
                            while(times-- > 0){
                                ls.add(sub);
                            }
                            break;
                        }else{
                            cnt--;
                        }
                    }
                }
            }else if(!Character.isDigit(s.charAt(i))){
                String temp = String.valueOf(s.charAt(i));
                ls.add(temp);
            }
        }
        String ans = "";
        for(String it : ls){
            ans += it;
        }
        return ans;
    }
    public String decodeString(String s) {
        String ans = solve(s);
        return ans;
    }
}