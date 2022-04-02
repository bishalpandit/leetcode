class Solution {

    int getVal(vector<vector<int>> &dungeon, int i, int j, vector<vector<int>> &dp) {
        int m = dungeon.size(), n = dungeon[0].size();
        if(i == m or j == n) return 1e9;
        if(i == m-1 and j == n-1) return dungeon[i][j] < 0 ? 1 - dungeon[i][j] : 1;
        
        if(dp[i][j] != 1e9) return dp[i][j];
        
        int down = getVal(dungeon, i+1, j, dp);
        int right = getVal(dungeon, i, j+1, dp);
        
        int minHP = min(down, right) - dungeon[i][j];
        
        return dp[i][j] = (minHP <= 0) ? 1 : minHP;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        vector<vector<int>> dp(dungeon.size()+1, vector<int>(dungeon[0].size()+1, 1e9));
        return getVal(dungeon, 0, 0, dp);
    }
};

// negative postive hai :)