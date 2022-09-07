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
    void f(TreeNode* root, string &ans) {
        if(!root) {
            ans += ')';
            return;
        }
        
        ans += to_string(root->val);
        
        if(root->right or root->left) {
            ans += '(';
            f(root->left, ans);
        }
        
        if(root->right) {
            ans += '(';
            f(root->right, ans);
        }
        
        ans += ')';
    }
public:
    string tree2str(TreeNode* root) {
        string ans;
        
        f(root, ans);
        
        return ans.substr(0, ans.size() - 1);
    }
};

/*
   1
   /\
   2 3
   /\ /\
  4     
*/