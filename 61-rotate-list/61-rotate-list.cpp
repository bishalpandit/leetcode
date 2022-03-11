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
    int getLength(ListNode* head) {
        if(!head) return 0;
        return 1 + getLength(head->next);
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        int n = getLength(head);
        k = k%n;
        
        if(k == 0) return head;
        
        int p = n - k - 1;
        ListNode* temp = head;
        ListNode* newHead;
        
        while(temp and temp->next) {
            if(p-- == 0) {
                newHead = temp->next;
                temp->next = NULL;
                temp = newHead;
                continue;
            }
            temp = temp->next;
        }
        
        temp->next = head;
        return newHead;
    }
};