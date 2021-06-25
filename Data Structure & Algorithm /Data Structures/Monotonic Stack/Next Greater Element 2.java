class Solution {
    // https://leetcode-cn.com/problems/next-greater-element-ii/submissions/
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        Stack<Integer> s = new Stack<>();
        for(int i = 0; i < n * 2; ++i){
            while(!s.isEmpty() && nums[s.peek()] < nums[i % n]){
                int t = s.pop();
                ans[t] = nums[i % n];
            }
            s.push(i % n);
        }
        return ans;
    }
}
