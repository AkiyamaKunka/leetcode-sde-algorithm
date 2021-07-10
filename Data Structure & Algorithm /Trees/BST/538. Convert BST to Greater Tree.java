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
    // https://leetcode-cn.com/problems/convert-bst-to-greater-tree/submissions/
    int cur_sum = 0;
    public void dfs(TreeNode cur){
        if(cur == null) return;
        // right, mid, left
        dfs(cur.right);
        cur_sum += cur.val;
        cur.val = cur_sum;
        dfs(cur.left);
    }
    public TreeNode convertBST(TreeNode root) {
        dfs(root);
        return root;
    }
}