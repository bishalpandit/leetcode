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
    void f(int row, int col, TreeNode* root, map<int, map<int, multiset<int>>> &colMap) {
        if(!root) return;
        
        colMap[col][row].insert(root->val);
        
        f(row + 1, col - 1, root->left, colMap);
        f(row + 1, col + 1, root->right, colMap);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> colMap;
        vector<vector<int>> ans;
        
        f(0, 0, root, colMap);
        
        for(auto &[c, list]: colMap) {
            vector<int> col;
            
            for(auto &[r, items]: list) 
                for(auto &val: items)
                    col.push_back(val);
            
            ans.push_back(col);
        }
        
        return ans;
    }
};