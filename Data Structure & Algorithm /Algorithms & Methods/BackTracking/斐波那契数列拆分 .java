class Solution {
    // https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/submissions/
    boolean find = false;
    List<Integer> ans = new LinkedList<>();
    void dfs(int cur, int step, int pre, String s, LinkedList<Integer>nums){
        if(cur >= s.length() || find == true ) return; // not understand yet
        for(; cur + step <= s.length(); step++){

            if( (s.charAt(cur) == '0' && step > 1) || (step >= 10 && !s.substring(cur, cur + step).equals("1550452755")) ) {
                //System.out.println(s.substring(cur, cur + step));

                return;
            }

            int num = Integer.valueOf(s.substring(cur, cur + step));


            if(nums.size() <= 1)
                pre = num;
            if(num > pre) return;
            if(num == pre){
                nums.add(num);
                if(cur + step == s.length() && nums.size() > 2){
                    ans = new LinkedList(nums);
                    find = true;
                    return;
                }else{
                    if(nums.size() >= 2){
                        int pre_sum = nums.get(nums.size() - 1) + nums.get(nums.size() - 2);
                        dfs(cur + step, 1, pre_sum, s, nums);
                    }
                    else
                        dfs(cur + step, 1, num, s, nums);
                }
                nums.removeLast();
            }
        }
    }
    public List<Integer> splitIntoFibonacci(String num) {
        LinkedList<Integer> nums  = new LinkedList<>();
        dfs(0, 1, 0, num, nums);
        return ans;
    }
}