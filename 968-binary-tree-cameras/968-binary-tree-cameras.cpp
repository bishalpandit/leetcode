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
    int res = 0;
    int f(TreeNode* root) {
        if(!root) return 2;
        
        int l = f(root->left);
        int r = f(root->right);
        
        if(l == 0 or r == 0) {
            res++;
            return 1;
        }
        
        return (l == 1 || r == 1) ? 2 : 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        return (f(root) < 1 ? 1 : 0) + res;
    }
};