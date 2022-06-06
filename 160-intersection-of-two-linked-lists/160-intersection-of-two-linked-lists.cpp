/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        
        while(a != b and (a or b)) {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }
        
      return a;
    }
};

/* 
1->2->3->8
4->5->0
*/