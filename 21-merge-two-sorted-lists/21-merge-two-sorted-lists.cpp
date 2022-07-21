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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *tail;
        tail = dummy;
        
        while(l1 and l2) {
            if(l1->val < l2-> val) {
                
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
                
            }
            else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
                
            }
        }
        
        if(l1) {
            tail->next = l1;
        }
        
        if(l2) {
            tail->next = l2;
        }
        
        return dummy->next;
        
    }
};

/*
1->2->4->5->6->7
1->3->4

dummyNode-> 1 -> 1 -> 2 -> 3 -> 4 -> 4

tail 

*/