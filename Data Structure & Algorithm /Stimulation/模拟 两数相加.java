/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    //https://leetcode-cn.com/problems/add-two-numbers/

    void add(ListNode n1, ListNode n2, ListNode pre, int preSum){
        if(n1 == null && n2 == null ) {
            if(preSum == 0)
                return;
            else{
                ListNode cur = new ListNode(1);
                pre.next = cur;
                return;
            }
        }

        int sum = preSum;
        if(n1 != null) sum += n1.val;
        if(n2 != null) sum += n2.val;
        int value = 0;
        if(sum > 9) {
            value = sum - 10;
            ListNode cur = new ListNode(value);
            pre.next = cur;
            if(n1 == null)
                add(null, n2.next, cur, 1);
            else if (n2 == null)
                add(n1.next, null, cur, 1);
            else
                add(n1.next, n2.next, cur, 1);
        }
        else {
            value = sum;
            ListNode cur = new ListNode(value);
            pre.next = cur;
            if(n1 == null)
                add(null, n2.next, cur, 0);
            else if (n2 == null)
                add(n1.next, null, cur, 0);
            else
                add(n1.next, n2.next, cur, 0);

        }


    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        add(l1, l2, head, 0);
        return head.next;
    }
}