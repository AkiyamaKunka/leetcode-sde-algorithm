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
    // https://leetcode-cn.com/problems/linked-list-cycle-ii/
    public ListNode detectCycle(ListNode head) {
        if(head == null) return null;
        ListNode slow, fast;
        slow = fast = head;
        do{
            if(slow.next != null && fast.next != null && fast.next.next != null){
                slow = slow.next;
                fast = fast.next.next;
            }else{
                return null;
            }
        }while(slow != fast);
        ListNode ans = head;
        while(slow != ans){
            slow = slow.next;
            ans = ans.next;
        }
        return ans;
    }
}


// a = stright
// b = from circle begin to converge
// c = from converge to circle begin
// fast pointer : s2 = a + b + n * (b + c);
// slow pointer : s1 = a + b
// and they will must meet in the slow pointer's first circle
// s2 = 2 * s1, then
// a + (n + 1) * b + n * c = 2 * a + 2 * b
// (b + c) * (n - 1) + c = a
// set a pointer from the head, then move the slow pointer, they will meet at the converge