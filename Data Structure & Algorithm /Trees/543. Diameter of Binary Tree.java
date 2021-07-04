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
    // 543. Diameter of Binary Tree
    int ans = 0;
    public int dfs(TreeNode n){
        if(n == null) return 0;
        int left = dfs(n.left);
        int right = dfs(n.right);
        int dif = Math.abs(left + right);
        ans = ans < dif ? dif : ans;
        return Math.max(left, right) + 1;
    }

    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return ans;
    }
}