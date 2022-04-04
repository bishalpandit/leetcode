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
    int len(ListNode* head) {
        if(head == NULL) return 0;
        return 1 + len(head->next);
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = len(head);
        int nk = n - k + 1;
        ListNode *n1, *n2, *h;
        h = head;
        
        while(head) {
            if(--k == 0)
                n1 = head;
             if(--nk == 0)
                 n2 = head;
            if(!nk and !k) break;
            head = head->next;
        }
        
        swap(n1->val, n2->val);
        
        return h;
    }
};