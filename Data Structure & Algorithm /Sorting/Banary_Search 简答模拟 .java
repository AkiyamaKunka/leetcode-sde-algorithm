class Solution {
    // https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
    int binary_search(int[] nums, int t, int l, int r){
        if(l > r) return -1;
        int m = l + (r - l) / 2;
        if(nums[m] == t) return m;
        if(t < nums[m]){
            r = m - 1;
        }else{
            l = m + 1;
        }
        return binary_search(nums, t, l, r);
    }
    public int[] searchRange(int[] nums, int target) {
        int [] ans = new int [2];
        ans[0] = -1;
        ans[1] = -1;
        int pre = binary_search(nums, target, 0, nums.length - 1);
        if(pre != -1){
            int l = pre;
            int r = pre;
            while(l != -1 && nums[l] == target){
                l--;
            }
            while(r != nums.length && nums[r] == target){
                r++;
            }
            ans[0] = l + 1;
            ans[1] = r - 1;
        }
        return ans;
    }
}