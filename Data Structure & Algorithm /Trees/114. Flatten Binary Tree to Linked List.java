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
    // https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
    public void pre(LinkedList<TreeNode>ls, TreeNode n){
        if(n == null) return;
        ls.add(n);
        pre(ls, n.left);
        pre(ls, n.right);
    }
    public void flatten(TreeNode root) {
        LinkedList<TreeNode> ls = new LinkedList<>();
        pre(ls, root);
        for(int i = 0; i < ls.size(); ++i){
            TreeNode n = ls.get(i);
            n.left = null;
            if(i != ls.size() - 1)
                n.right = ls.get(i + 1);
            else n.right = null;
        }
    }
}