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
    ListNode* swapPairs(ListNode* head) {
        auto p = head;
        if(head == NULL or head->next == NULL) return head;
        ListNode* cur, *prev;
        ListNode* dummy = new ListNode(0);
        prev = dummy;
        cur = head;
        
        while(cur) {
            if(!cur->next)
                break;
            prev->next = cur->next;
            if(cur->next) 
                cur->next = cur->next->next;
            else
                cur->next = NULL;
            if(prev->next)
                prev->next->next = cur;
        
            prev = cur;
            cur = cur->next;
        }
        
        return dummy->next;
    }
};