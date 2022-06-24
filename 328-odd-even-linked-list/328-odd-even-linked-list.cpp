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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *dummy1 = new ListNode(0), *dummy2 = new ListNode(0), *t1 = dummy1, *t2 = dummy2;
        int cnt = 1;
        
        auto temp = head;
        
        while(temp) {
            if(cnt&1) {
                t1->next = temp;
                t1 = temp;
            }
            else {
                t2->next = temp;
                t2 = temp;
            }
            cnt++;
            temp = temp->next;
        }
        
        t2->next = NULL;
        t1->next = dummy2->next;
        return dummy1->next;
    }
};

/*

even_tail -> 0->2->4
odd_tail -> 0->1->3->5
1 2 3 4 5

*/