class Solution {
    int dp[201][201];
    int f(vector<vector<int>> &t, int r, int c, int n) {
        if(r == n - 1) return t[r][c]; // last row huh? only option, just take dude
        
        if(dp[r][c] != -1) return dp[r][c]; // Have I seen you before? Yes if I'm not -1.
        
        return dp[r][c] = t[r][c] + min(f(t, r + 1, c, n), f(t, r + 1, c + 1, n)); // go left, go right, get me minimum value.
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memset(dp, -1, sizeof(dp));
        return f(triangle, 0, 0, n);
    }
};