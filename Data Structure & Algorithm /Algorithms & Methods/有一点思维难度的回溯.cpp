class Solution8 {
    // https://leetcode-cn.com/problems/merge-two-sorted-lists/
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode * fun(ListNode * node1, ListNode * node2){
        if(node1 == nullptr ) {
            return node2;
        }
        if(node2 == nullptr  ){
            return node1;
        }

        if(node1->val > node2->val) {
            node2->next = fun(node1, node2->next);
            return node2;
        }else{
            node1->next = fun(node1->next, node2);
            return node1;
        };
    }
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return fun(l1, l2);
    }
};