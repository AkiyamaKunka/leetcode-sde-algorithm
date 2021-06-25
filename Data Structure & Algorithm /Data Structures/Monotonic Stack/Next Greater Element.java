class Solution {
    // https://leetcode-cn.com/problems/next-greater-element-i/submissions/
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int [] res = new int[n2];
        Stack<Integer> s = new Stack<>();
        for(int i = 0; i < n2; ++i){
            if(s.isEmpty() || nums2[s.peek()] >= nums2[i]){
                s.push(i);
            }else{
                while(!s.isEmpty() && nums2[s.peek()] < nums2[i]){
                    int t = s.peek();
                    res[t] = i - t;
                    s.pop();
                }
                s.push(i);
            }
        }
        int [] ans = new int[n1];
        for(int i = 0; i < n1; ++i){
            for(int j = 0; j < n2; ++j){
                if(nums1[i] == nums2[j]){
                    if(res[j] == 0) ans[i] = -1;
                    else{
                        ans[i] = nums2[j + res[j]];
                    }
                    break;
                }
            }
        }
        return ans;
    }
}