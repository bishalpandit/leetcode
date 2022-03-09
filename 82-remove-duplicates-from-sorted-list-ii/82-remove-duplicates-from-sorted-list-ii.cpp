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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode* temp = head;
        int cnt = 0;
        
        while(temp) {
            dupagain:
            if(temp->next and temp->val == temp->next->val) {
                while(temp->next and temp->val == temp->next->val)
                    temp = temp->next;
                if(temp->next and temp->next->next and temp->next->val == temp->next->next->val) {
                    temp = temp->next;
                    goto dupagain;
                }
                prev->next = temp->next;
            } 
            
            else {
                if(++cnt == 1)
                    prev->next = temp;
                prev = temp;
            }
            
            temp = temp->next;
        }
        
        return (dummy->next == head) ? head : dummy->next;
    }
};