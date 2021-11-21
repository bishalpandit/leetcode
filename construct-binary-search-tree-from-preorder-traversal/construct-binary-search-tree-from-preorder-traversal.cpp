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
    TreeNode* buildBT(vector<int> &inorder, int sin, int ein, vector<int> &preorder, int spre, int epre) {
        if(sin > ein or spre > epre)
            return NULL;
        
        int preRootVal = preorder[spre];
        int inRootIndex = find(inorder.begin(),inorder.end(),preRootVal) - inorder.begin();
        int noOfLeftNodes = inRootIndex - sin;
        
        TreeNode *root = new TreeNode(preRootVal);
        root->left = buildBT(inorder, sin, inRootIndex-1, preorder, spre+1, spre + noOfLeftNodes);
        root->right = buildBT(inorder, inRootIndex+1, ein, preorder, spre+noOfLeftNodes+1, epre);
        
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        for(int &val: preorder)
            inorder.push_back(val);
        sort(inorder.begin(), inorder.end());
        int inSize = inorder.size(), preSize = preorder.size();
        return buildBT(inorder, 0, inSize-1, preorder, 0, preSize-1);
    }
};

/*
            
Inorder ->  1 5 7  | 8  | 10 12
            0 1 2   3       4 5
Preorder -> 8 | 5 1 7 | 10 12
            0   1 2 3  4  5
            root  L      R
*/