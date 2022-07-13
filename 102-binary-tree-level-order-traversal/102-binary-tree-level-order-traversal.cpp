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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.size()) {
            vector<int> level;
            int n = q.size();
            
            for(int i = 0; i < n; i++) {
                auto node = q.front(); q.pop();
                
                level.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            ans.push_back(level);
        }
        
        return ans;
    }
};