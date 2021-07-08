class Solution {
    public int search(int[] nums, int t, int l, int r){
        //https://leetcode-cn.com/problems/search-insert-position/
        if(l > r) return l;
        int m = l + (r - l) / 2;
        if(nums[m] < t) l = m + 1;
        else if(nums[m] > t) r = m - 1;
        else return m;
        return search(nums, t, l, r);

    }
    public int searchInsert(int[] nums, int target) {
        int ans = search(nums, target, 0, nums.length - 1);
        return ans;
    }
}