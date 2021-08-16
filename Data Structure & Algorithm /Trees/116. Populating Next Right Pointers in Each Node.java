/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {

    public Node connect(Node root) {
        if(root == null) return null;
        int layer = 0;
        Queue<Node> q = new LinkedList<>();

        q.add(root);
        while(!q.isEmpty()){
            Node pre = null;
            for(int i = 0; i < Math.pow(2, layer); ++i){
                Node cur = q.poll();
                if(i == 0){
                    pre = cur;
                }else{
                    //System.out.println(cur.val +  " points " + pre.val);
                    cur.next = pre;
                    pre = cur;
                }
                if(cur.right != null) q.add(cur.right);
                if(cur.left != null) q.add(cur.left);
            }
            layer++;
        }
        return root;
    }
}
