class Solution {
    // https://leetcode-cn.com/problems/subarray-sum-equals-k/
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        int pre = 0;
        Map<Integer, Integer> map = new HashMap<>();
        //map.put(0, 1); // before index of 0, the sum is 0, exist one like that
        for(int num : nums){
            pre += num;
            if(map.containsKey(pre - k)) ans += map.get(pre - k);
            map.put(pre, map.getOrDefault(pre, 0) + 1);
        }

        return ans;
    }
}