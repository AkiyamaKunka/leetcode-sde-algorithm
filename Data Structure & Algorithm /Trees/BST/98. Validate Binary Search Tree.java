/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    // https://leetcode-cn.com/problems/validate-binary-search-tree/submissions/
    boolean ans = true;
    public int[] dfs(TreeNode cur){
        if(cur == null || ans == false) return null;
        int[] bd = new int[2];
        int[] left = dfs(cur.left);
        int[] right = dfs(cur.right);
        if(left != null){
            if(left[1] >= cur.val) ans = false;
        }
        if(right != null){
            if(right[0] <= cur.val) ans = false;
        }
        bd[0] = left == null ? cur.val : left[0];
        bd[1] = right == null ? cur.val : right[1];
        return bd;
    }

    public boolean isValidBST(TreeNode root) {
        dfs(root);
        return ans;
    }

}