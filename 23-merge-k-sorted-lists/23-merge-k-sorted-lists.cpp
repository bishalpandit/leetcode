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
    ListNode* mergeLists(ListNode* l1, ListNode*  l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        
        while(l1 and l2) {
            
            if(l1->val <= l2->val) {
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
        
        while(l1) {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        
        while(l2) {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
        
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        if(lists.size() == 1)
            return lists[0];
        
        ListNode* mergedList;
        
        
      
        for(int i=0; i<lists.size()-1; i++) {
            ListNode* l1 = lists[i];
            ListNode* l2 = lists[i+1] ;
            
            mergedList = mergeLists(l1, l2);
            lists[i+1] = mergedList;
        }
        
        return mergedList;
    }
};

/*
1
1->3->4

dummy->1->1->3->4->4->5 

1, 2, 4, 5
*/