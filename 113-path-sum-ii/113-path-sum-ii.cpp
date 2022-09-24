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
    void solve(TreeNode* node, int target, vector<int>& path, vector<vector<int>>& validPaths) {
        if(!node)
            return;
        
        if(!node->left && !node->right) {
            if(target - node->val == 0) {
                path.push_back(node->val);
                validPaths.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        
        path.push_back(node->val);
        solve(node->left, target - node->val, path, validPaths);
        solve(node->right, target - node->val, path, validPaths);
        path.pop_back();
        
    } 
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> validPaths;
        vector<int> path;
        
        solve(root, targetSum, path, validPaths);
        return validPaths;
    }
};