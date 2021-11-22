class Solution {
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, vector<bool>& vis) {
        int n = nums.size();
        if(n == subset.size()) {
            ans.push_back(subset);
            return;
        }
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                vis[i] = true;
                subset.push_back(nums[i]);
                solve(nums, ans, subset, vis);
                vis[i] = false;
                subset.pop_back();
            }
        }
    } 
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subset;
        vector<bool> vis(n);
        solve(nums, ans, subset, vis);
        return ans;
    }
};

/*

i. Keep a vis array
ii. when  you reach the end of array, take the vec into vec or vec.
iii.

*/