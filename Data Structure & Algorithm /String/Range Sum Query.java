class NumArray {
    // https://leetcode-cn.com/problems/range-sum-query-immutable/
    int [] sum;
    int [] myNums;
    public NumArray(int[] nums) {

        int n = nums.length;
        sum = new int[n];
        myNums = new int[n];
        int pre = 0;
        for(int i = 0; i < n; ++i){
            sum[i] = pre + nums[i];
            pre = sum[i];
            myNums[i] = nums[i];
        }
    }

    public int sumRange(int left, int right) {
        int res = sum[right] - sum[left] + myNums[left];
        return res;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */