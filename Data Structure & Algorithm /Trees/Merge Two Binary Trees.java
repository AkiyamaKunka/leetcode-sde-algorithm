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
    // https://leetcode-cn.com/problems/merge-two-binary-trees/
    public TreeNode bfs(TreeNode r1, TreeNode r2){
        if(r1 == null && r2 == null) return null;
        TreeNode r3 = new TreeNode();
        int v1 = (r1 == null ? 0 : r1.val);
        int v2 = (r2 == null ? 0 : r2.val);
        int value = v1 + v2;
        r3.val = value;
        TreeNode r1_left, r1_right, r2_left, r2_right;
        if(r1 == null){
            r1_left = r1_right = null;
        }else{
            r1_left = r1.left;
            r1_right = r1.right;
        }
        if(r2 == null){
            r2_left = r2_right = null;
        }else{
            r2_left = r2.left;
            r2_right = r2.right;
        }
        r3.left = bfs(r1_left, r2_left);
        r3.right = bfs(r1_right, r2_right);
        return r3;
    }

    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        TreeNode ans = bfs(root1, root2);
        return ans;
    }
}