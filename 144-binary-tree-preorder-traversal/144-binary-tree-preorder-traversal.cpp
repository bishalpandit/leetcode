/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        TreeNode* node = root;
        
        stack<TreeNode*> st;
        vector<int> ans;
        
        while(node or !st.empty()) {
            
            if(node) {
                ans.push_back(node->val);
                st.push(node);
                node = node->left;
            }
            
            else {
                
                TreeNode* topNode = st.top(); st.pop();
                
                if(topNode->right) {
                    node = topNode->right;
                }
            }
            
        }
            
        return ans;
    }
};