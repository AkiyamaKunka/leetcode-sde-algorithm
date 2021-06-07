class Solution {
    // https://leetcode-cn.com/problems/container-with-most-water/submissions/
    public int maxArea(int[] height) {
        int ans = -1;
        int l = 0;
        int r = height.length - 1;
        while(l < r){
            int area = (r - l) * Math.min(height[l], height[r]);
            if(ans < area) ans = area;
            if(height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
}