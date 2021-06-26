class Solution {
    // https://leetcode-cn.com/problems/search-in-rotated-sorted-array/submissions/
    int bs(int [] nums, int l, int r){
        if(l >= r) return -1;
        int m = l + (r - l) / 2;
        if(l + 1 == r){
            if(nums[l] > nums[r]) return r;
            else return -1;
        }
        else{
            if(nums[l] > nums[m]) return bs(nums, l, m);
            else return bs(nums, m, r);
        }
    }

    int bs2(int [] nums, int l, int r, int t){
        if(l > r ) return -1;
        int m = l + (r - l) / 2;
        if(nums[m] == t) return m;
        else if(nums[m] < t) return bs2(nums, m + 1, r, t);
        else return bs2(nums, l, m -1, t);

    }

    public int search(int[] nums, int target) {

        int pv = bs(nums, 0, nums.length - 1);

        if(pv == -1) pv = 1;
        int ans = Math.max(bs2(nums, 0, pv - 1, target), bs2(nums, pv, nums.length - 1, target));
        return ans;
    }
}