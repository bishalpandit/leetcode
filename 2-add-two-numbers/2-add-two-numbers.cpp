/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0, sum = 0, digit = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while(l1 or l2 or c) {
            int d1 = l1 ? l1->val : 0;
            int d2 = l2 ? l2->val : 0;
            
            sum = d1 + d2 + c;
            digit = sum%10;
            c = sum/10;
            
            tail->next = new ListNode(digit);
            tail = tail->next;
            
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        
        return dummy->next;
    }
};

