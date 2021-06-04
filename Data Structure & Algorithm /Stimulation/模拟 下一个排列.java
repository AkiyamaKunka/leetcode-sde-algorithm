class Solution {
    //https://leetcode-cn.com/problems/next-permutation/submissions/
    void swap(int i, int j, int[] nums){
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length;
        if(n < 2) return;
        int i = n - 2;
        for(; i >= 0; --i){
            if(nums[i] < nums[i + 1]){
                break;
            }
        } // 找到第一个降序的位置
        if(i != -1){
            int p = i + 1;
            for(int k = i + 1; k < n; k++){
                if(nums[k] > nums[i]){
                    if(p == i + 1){ // 第一次遇到比他大的数
                        p = k;
                    }else{ // 第二次以上遇到比他大的数
                        if(nums[p] > nums[k]) // 这个新的数更小
                            p = k;
                    }
                }
            }
            swap(i, p, nums);
        }
        Arrays.sort(nums, i + 1, n);
    }
}