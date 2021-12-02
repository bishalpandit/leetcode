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
        if(head == 0x0)
            return 0x0;
        if(head->next == NULL)
            return head;
        
        vector<int> LL;
        auto *temp = head;
        while(temp) {
            LL.push_back(temp->val);
            temp = temp->next;
        }
        
        ListNode *tail1, *tail2;
        ListNode dummy1(0), dummy2(0);
        tail1 = &dummy1, tail2 = &dummy2;
        
        for(int i=0; i<LL.size(); i++) {
            if(i&1) {
                ListNode *newNode = new ListNode(LL[i]);
                tail2->next = newNode;
                tail2 = newNode;
            }
            
            else {
                ListNode *newNode = new ListNode(LL[i]);
                tail1->next = newNode;
                tail1 = newNode;
            }
        }
        
        ListNode *head1 = dummy1.next;
        
        while(head1->next) {
            head1 = head1->next;
        }
        
        head1->next = dummy2.next;
        
        
        return dummy1.next;
    }
};


// 1 2 3 4 5