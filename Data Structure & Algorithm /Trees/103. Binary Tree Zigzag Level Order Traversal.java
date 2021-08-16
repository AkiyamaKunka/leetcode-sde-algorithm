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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<>();
        if(root == null) return ans;
        boolean isLeft = false;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int n = q.size();
            TreeNode cur = null;
            List<Integer> sub_ans = new LinkedList<>();
            for(int i = 0; i < n; ++i){
                cur = q.poll();
                sub_ans.add(cur.val);
                if(cur.left != null)
                    q.add(cur.left);
                if(cur.right != null)
                    q.add(cur.right);
            }
            if(isLeft) Collections.reverse(sub_ans);
            ans.add(sub_ans);
            isLeft = !isLeft;

        }
        return ans;
    }
}
