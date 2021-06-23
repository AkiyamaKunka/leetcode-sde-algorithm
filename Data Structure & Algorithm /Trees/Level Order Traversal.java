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
    public List<List<Integer>> levelOrder(TreeNode root) {
        // https://leetcode-cn.com/problems/binary-tree-level-order-traversal/submissions/
        Queue<TreeNode> q = new ArrayDeque<>();
        List<List<Integer>> ans = new LinkedList<>();
        if(root == null) return ans;
        q.add(root);
        while(!q.isEmpty()){
            List<Integer> sub_ans = new LinkedList<>();
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode t = q.poll();
                sub_ans.add(t. val);
                if(t.left != null)
                    q.add(t.left);
                if(t.right != null)
                    q.add(t.right);
            }
            ans.add(sub_ans);
        }
        return ans;
    }
}