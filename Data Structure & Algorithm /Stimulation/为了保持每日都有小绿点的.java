/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    //https://leetcode-cn.com/problems/reverse-linked-list/submissions/
    ListNode ans;
    void dfs(ListNode pre, ListNode cur){
        ListNode nx = cur.next;
        cur.next = pre;
        if(nx == null){
            ans = cur;
            return;
        }
        dfs(cur, nx);
    }

    public ListNode reverseList(ListNode head) {
        if(head == null) return null;
        dfs(null, head);
        return ans;
    }
}