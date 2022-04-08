class Solution {
    int solve(string &s, int i, vector<int> &dp) {
        if(i < 0)
            return 1;
        if(dp[i] != -1)
            return dp[i];
        
        int op1 = 0, op2 = 0;
        
        if(s[i] != '0') 
            op1 = solve(s, i-1, dp);
        
        if(i > 0 and s[i-1] != '0' and (s[i-1]-'0') <= 2 and !(s[i-1] == '2' and (s[i] - '0') > 6)) 
           op2 = solve(s, i-2, dp);
        
        return dp[i] = op1 + op2;
    }
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len, -1);
        return solve(s, len-1, dp);
    }
};