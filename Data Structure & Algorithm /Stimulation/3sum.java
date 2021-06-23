class Solution {
    // https://leetcode-cn.com/problems/3sum/submissions/
    // 排序可以很巧妙地完成去重的过程。
    // 这又是一类双指针的题目
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new LinkedList<>();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length - 2; i++){
            if(nums[i] > 0) break;
            if(i != 0 && nums[i - 1] == nums[i]) continue;
            int j = i + 1;
            int k = nums.length - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){ //
                    while(j < k && nums[k] == nums[--k]);
                }else if (sum < 0){
                    while(j < k && nums[j] == nums[++j]);
                }else{
                    ans.add(new ArrayList(Arrays.asList(nums[i], nums[j], nums[k])));
                    while(j < k && nums[j] == nums[++j]);
                    while(j < k && nums[k] == nums[--k]);
                }
            }
        }
        return ans;
    }
}

