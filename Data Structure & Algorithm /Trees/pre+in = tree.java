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
    //https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/
    private TreeNode solve(int[] preorder, int[] inorder, int sp, int ep, int si, int ei){
        if(sp == ep) return null;
        int rt_val = preorder[sp];
        int rt_id_in = 0;
        for(int i = si; i < ei; ++i){
            if(rt_val == inorder[i]){
                rt_id_in = i;
                break;
            }
        }
        TreeNode rootNode = new TreeNode(rt_val);
        int left_num = rt_id_in - si;
        int right_num = ei - 1 - left_num;


        rootNode.left = solve(preorder, inorder, sp + 1, sp + 1 + left_num, si, rt_id_in);
        rootNode.right = solve(preorder, inorder, sp + 1 + left_num, ep , rt_id_in + 1, ei);



        return rootNode;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return solve(preorder, inorder, 0, preorder.length, 0, inorder.length);

    }
}

