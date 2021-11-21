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
    
    TreeNode* buildBT(vector<int> &inorder, int sin, int ein, vector<int> &postorder, int spost, int epost) {
        if(sin > ein or spost > epost)
            return NULL;
        int preRootVal = postorder[epost];
        int inRootIndex = find(inorder.begin(),inorder.end(),preRootVal) - inorder.begin();
        int noOfRightNodes = ein - inRootIndex;
        TreeNode *root = new TreeNode(preRootVal);
        root->left = buildBT(inorder, sin, inRootIndex-1, postorder, spost, epost - noOfRightNodes - 1);
        root->right = buildBT(inorder, inRootIndex+1, ein, postorder, epost - noOfRightNodes, epost - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inSize = inorder.size(), postSize = postorder.size();
        return buildBT(inorder, 0, inSize-1, postorder, 0, postSize-1);
    }
};


/*
            L   root  R
Inorder ->  9 | 3  | 15 20 7
            0   1    2 3  4
Postorder -> 9  | 15 7 20 | 3
             0    1  2  3   4
             L    R        root
*/