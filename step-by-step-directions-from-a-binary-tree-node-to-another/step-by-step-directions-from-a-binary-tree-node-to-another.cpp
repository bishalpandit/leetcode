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
    
    TreeNode* findLCA(TreeNode* root, int node1, int node2, TreeNode* &start, TreeNode* &dest) {
        if(root == NULL)
            return root;
        if(root->val == node1 or root->val == node2) {
            if(root->val == node1)
                start = root;
            else dest = root;
            return root;
        }
        
        auto left = findLCA(root->left, node1, node2, start, dest);
        auto right = findLCA(root->right, node1, node2, start, dest);
        
        if(!left)
            return right;
        if(!right)
            return left;
        
        return root;
        
    }
    bool buildPath(TreeNode* lca, int node, string &path) {
        if(lca == NULL)
            return false;
        if(lca->val == node)
            return true;
        
        path += "L";
        auto left = buildPath(lca->left, node, path);
        if(left)
            return true;
        path.pop_back();
        path += "R";
        auto right = buildPath(lca->right, node, path);
        if(right)
            return true;
        path.pop_back();
        
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *start, *dest;
        auto lca = findLCA(root, startValue, destValue, start, dest);
        
        string temp;
        string path1, path2;

        buildPath(lca, startValue, path1);
        buildPath(lca, destValue, path2);
        
        
        for(auto &ch: path1)
            ch = 'U';
        
        string ans = path1 + path2;
        
        return ans;
    }
};