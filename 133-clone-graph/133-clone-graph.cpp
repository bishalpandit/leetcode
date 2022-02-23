/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<int, Node*> nodeMap;
        if(!node)
            return NULL;
        queue<Node*> q;
        
        q.push(node);
        Node* newNode = new Node(node->val);
        nodeMap.insert({newNode->val, newNode});

        
        while(!q.empty()) {
            Node* orig_node = q.front(); q.pop(); // orig_node.val, orig_node.neighbors


            for(auto ref: orig_node->neighbors) {

                if(nodeMap.find(ref->val) == nodeMap.end()) {
                    Node* adjNode = new Node(ref->val);
                    nodeMap.insert({adjNode->val, adjNode});
                    q.push(ref);
                }
                
                nodeMap[orig_node->val]->neighbors.push_back(nodeMap[ref->val]);
                
            } 
            
        }
        
        return newNode;
        
    }
};

/*

1, 2, 3, 4

*/