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
    ListNode* partition(ListNode* head, int x) {
        if(!head or !head->next)
            return head;
        ListNode *dummy1 = new ListNode(0), *dummy2 = new ListNode(0), *t1, *t2, *temp;
        t1 = dummy1, t2 = dummy2;
        t1->next = NULL, t2->next = NULL;
        temp = head;
        
        while(temp) {
            if(temp->val < x) {
                t1->next = new ListNode(temp->val);
                t1 = t1->next;
            }
            temp = temp->next;
        }
        
        while(head) {
            if(head->val >= x) {
                t2->next = new ListNode(head->val);
                t2 = t2->next;
            }
            head = head->next;
        }
        
        if(!dummy1->next)
            return dummy2->next;
        
        if(!dummy2->next)
            return dummy1->next;
        
        t1->next = dummy2->next;
        dummy2->next = NULL;
        
        return dummy1->next;
    }
};