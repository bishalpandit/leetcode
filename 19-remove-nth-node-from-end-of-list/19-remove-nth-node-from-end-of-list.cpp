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
    ListNode* f(ListNode* node, int &n) {
        if(node == NULL)
            return node;
        
        auto next = f(node->next, n);
        node->next = next;
        
        if(--n == 0) {
            node->next = NULL;
            return next;
        }
        
        return node;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return f(head, n);
    }
};

/*

3 -> 4 -> 5
- last node return null
- target node, return the next node to prev when n = 0

1
*/