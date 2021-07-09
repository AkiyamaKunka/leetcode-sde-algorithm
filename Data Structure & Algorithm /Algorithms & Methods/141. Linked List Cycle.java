/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    // https://leetcode-cn.com/problems/linked-list-cycle/
    public boolean hasCycle(ListNode head) {
        if(head == null) return false;
        ListNode slow, fast;
        slow = fast = head;
        do{
            if(slow.next != null && fast.next != null && fast.next.next != null){
                slow = slow.next;
                fast = fast.next.next;
            }else{
                return false;
            }
        }while(slow != fast);
        return true;
    }
}