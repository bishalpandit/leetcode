class Solution {
    int solve(string &word1, string &word2, int m, int n, vector<vector<int>> &dp) {
        if(m < 0) return n + 1;
        if(n < 0) return m + 1;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        if(word1[m] == word2[n]) return solve(word1, word2, m-1, n-1, dp);
        
        else {
        return dp[m][n] = 1 + min(solve(word1, word2, m-1, n-1, dp), min(solve(word1, word2, m-1, n, dp), solve(word1, word2, m, n-1, dp)));
        }
     }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return solve(word1, word2, m-1, n-1, dp);
    }
};