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
    TreeNode* f(vector<int>& nums, int low, int high) {
        if(low > high) return NULL;

        int mid = (low + high)/2;
        
        TreeNode* node = new TreeNode(nums[mid]);
        node->right =  f(nums, mid + 1, high);
        node->left =  f(nums, low, mid - 1);
        
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return f(nums, 0, nums.size() - 1);
    }
};

/*


-10 -3 0 5 9
-10, |3 -3, |2 0 |1 5, 9

if low > high
    return NULL

left = leftCall
right = rightCall

node = new TreeNode
node->right = right
node->left = left

return node

low high
*/