class Solution {
    int f(vector<int>& muls, vector<int>& nums, int i, int j, int x, vector<vector<int>> &dp) {
        if(x == muls.size()) 
            return 0;
        
        if(dp[x][i] != INT_MIN)
            return dp[x][i];
        
        int op1 = (muls[x] * nums[i]) + f(muls, nums, i + 1, j, x + 1, dp);
        int op2 = (muls[x] * nums[j]) + f(muls, nums, i, j - 1, x + 1, dp);
        
        return dp[x][i] = max(op1, op2);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MIN));
        
        return f(multipliers, nums, 0, n - 1, 0, dp);
    }
};