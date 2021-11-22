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
    bool isLeaf(TreeNode* root) {
        return !root->left and !root->right ? true : false;
    }
    
    
    TreeNode* connectChild(TreeNode* root) {
        if(isLeaf(root))
            return NULL;
        if(!root->left)
            return root->right;
        if(!root->right)
            return root->left;
        auto rightChild = root->right;
        auto leftRightMost = findRightMostNode(root->left);
        leftRightMost->right = rightChild;
        return root->left;
    }
    
    TreeNode* findRightMostNode(TreeNode* root) {
        if(!root->right)
            return root;
        while(root->right)
            root = root->right;
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        
        if(root->val == key) return connectChild(root);
        auto node = root;
        while(root) {
            
            if(key < root->val) {
                if(root->left and root->left->val == key) {
                    root->left = connectChild(root->left);
                    break;
                }
                else
                    root = root->left;
            }
            
            else if(key > root->val) {
                if(root->right and root->right->val == key) {
                    root->right = connectChild(root->right);
                    break;
                }
                else
                    root = root->right;
            }
        }
        
        return node;
            
    }
};
// findKey -> Found, Not found return root
// Key found -> In case root is key, return left or right or connect left right and return
// In case key is non-root, both child present : take left child and go as right as possible and connect right to it.
// only right or left exists : can directly connect and return
// none present : just return 2  4
