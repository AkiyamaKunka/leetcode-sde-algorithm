class Solution {
    // https://leetcode-cn.com/problems/daily-temperatures/
    public int [] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int [] ans = new int [n];
        Stack<Integer> s = new Stack<>();
        for(int i = 0; i < n; ++i){
            if(s.isEmpty() || temperatures[s.peek()] >= temperatures[i]){
                s.push(i);
            }else{
                while(!s.isEmpty() && temperatures[s.peek()] < temperatures[i]){
                    int t = s.peek();
                    ans[t] = i - t;
                    s.pop();
                }
                s.push(i);
            }
        }
        return ans;
    }
}