/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        map<Node*, pair<int, int>> old_addrToIdx;
        map<int, pair<int, Node*>> new_idxToAddr;
        
        Node* dummy = new Node(0);
        Node* cur = dummy;
        Node* temp = head;
        int idx = 0;
        
        while(temp) { // Constructing addToIdx Map
            old_addrToIdx.insert({temp, {idx++, temp->val}});
            temp = temp->next;
        }
        
        int n = idx;
        
        idx = 0;
        
        while(head) {
            Node* curNewNode;
            
            if(!new_idxToAddr.count(idx)) {
                curNewNode = new Node(head->val);
                new_idxToAddr.insert({idx, {curNewNode->val, curNewNode}});
                
            } else {
                curNewNode = new_idxToAddr[idx].second;
            }
            
            int randomToIdx = head->random ? old_addrToIdx[head->random].first : -1;
            
            if(randomToIdx != -1) {
                Node* curRandomNode;
                
                if(!new_idxToAddr.count(randomToIdx)) {
                    curRandomNode = new Node(head->random->val);
                    new_idxToAddr.insert({randomToIdx, {curRandomNode->val, curRandomNode}});
                    
                } else {
                    curRandomNode = new_idxToAddr[randomToIdx].second;
                }
                
                curNewNode->random = curRandomNode;
            }
            
            if(idx == 0) { // Not necessary
                dummy->next = curNewNode;
            }
            
            if(head->next) {
                int nextNodeIdx = old_addrToIdx[head->next].first;
                Node* curNextNode;
                
                if(!new_idxToAddr.count(nextNodeIdx)) {
                    curNextNode = new Node(head->next->val);
                    new_idxToAddr.insert({nextNodeIdx, {curNextNode->val, curNextNode}});
                    
                } else {
                    curNextNode = new_idxToAddr[nextNodeIdx].second;
                }
                
                curNewNode->next = curNextNode;
            }
            
            head = head->next;
            idx++;
        }
        
        return dummy->next;
    }
};

/*
random == cur -> self-loop
random == cur->next -> next node
*/