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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *n1 = nullptr, *n2 = nullptr, *p;
        p = head;
        
        while(p) {
            n2 = (n2 == nullptr) ? nullptr : n2->next;
            if(!--k) {
                n1 = p;
                n2 = head;
            }
            p = p->next;
        }
        
        swap(n1->val, n2->val);
        
        return head;
    }
};