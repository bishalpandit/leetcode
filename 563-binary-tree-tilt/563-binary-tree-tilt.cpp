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
    
int getSubtreeSum(TreeNode* node) {
    if(node == 0x0) return 0;
    return node->val + getSubtreeSum(node->left) + getSubtreeSum(node->right);
}
    
public:
    int findTilt(TreeNode* root) {
        if(root == NULL) return 0;
        
        return abs(getSubtreeSum(root->left) - getSubtreeSum(root->right)) + findTilt(root->left) + findTilt(root->right);
    }
};