class Solution {
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        if(i == grid.size()-1 and j == grid[0].size()-1) return grid[i][j];
        if(i == grid.size() or j == grid[0].size()) return 1e9;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = (grid[i][j] + min(solve(grid, i+1, j, dp), solve(grid, i, j+1, dp)));
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, 0, 0, dp);
    }
};

// TC -> 2^n SC -> O(m+n)