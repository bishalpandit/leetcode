class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        
        string revs = string(s.rbegin(), s.rend());
        
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
        
        for(int i=1; i<=len; i++)
            for(int j=1; j<=len; j++) {
                if(revs[i-1] == s[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        
        return dp[len][len];
        
    }
};


/*
racecar
racecar
bbbab
babbb
acdee
eedca
*/