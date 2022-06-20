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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next) return head;
        
        ListNode *before = NULL, *after = NULL, *prev = NULL, *cur = head, *l, *r;
        int cnt = 1;
        
        while(cur) {
            if(cnt == left - 1) before = cur;
            if(cnt == right + 1) after = cur;
            if(cnt == left) l = cur;
            if(cnt == right) r = cur;
            
            ListNode* next = NULL;
            
            if(cnt > left and cnt <= right) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
                cnt++;
                continue;
            }
            
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        
        l->next = after;
        
        if(before)
            before->next = r;
        
        return before ? head : r;
    }
};

/*
1->2

*/