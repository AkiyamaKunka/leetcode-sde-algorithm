class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int b1 = nums1.size();
        int b2 = nums2.size();
        for (int i = 0; i < b1; i++)
            for (int j = i + ans; j < b2; j++) {
                if(nums1[i] > nums2[j]) {
                    break;
                }
                if (j - i > ans && nums1[i] <= nums2[j])
                    ans = j - i;
            }

        return ans;
    }
};