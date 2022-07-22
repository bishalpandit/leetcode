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
        ListNode dummy1(0), dummy2(0);
        ListNode *t1 = &dummy1, *t2 = &dummy2;
        
        while(head) {
            if(head->val < x) 
                t1 = t1->next = head;
            else
                t2 = t2->next = head;
            head = head->next;
        }
        t2->next = NULL; // Break unwanted connection.
        t1->next = dummy2.next; // Connect list1 with list2
        
        return dummy1.next;
    }
};