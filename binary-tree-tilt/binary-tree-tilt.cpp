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
    
    int leftSubSum(TreeNode* root) {
        if(!root)
            return 0;
        return root->val + leftSubSum(root->left) + leftSubSum(root->right);
    }
    
    int rightSubSum(TreeNode* root) {
        if(root == 0x0)
            return 0;
        return root->val + rightSubSum(root->left) + rightSubSum(root->right);
    }
    
public:
    int findTilt(TreeNode* root) {
        if(root == 0x0)
            return 0;
        return abs((root->left ? leftSubSum(root->left) : 0) - (root->right ? rightSubSum(root->right) : 0)) + findTilt(root->left) + findTilt(root->right);
    }
};