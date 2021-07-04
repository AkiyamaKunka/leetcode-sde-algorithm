/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    // https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
    int ans = -0x3f3f3f3f;
    TreeNode ans_node = null;
    int v1;
    int v2;
    public boolean dfs(TreeNode n){
        if(n == null) return false;
        if(n.val == v1 || n.val == v2){
            if((dfs(n.left) || dfs(n.right)) && ans == -0x3f3f3f3f){
                ans = n.val;
                ans_node = n;
            }
            return true;
        }else{
            boolean l = dfs(n.left);
            boolean r = dfs(n.right);
            if( (l && r) && ans == -0x3f3f3f3f){
                ans = n.val;
                ans_node = n;
            }
            return (l || r);
        }
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        v1 = p.val;
        v2 = q.val;
        dfs(root);
        return ans_node;
    }
}