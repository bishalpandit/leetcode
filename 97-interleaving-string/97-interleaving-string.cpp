class Solution {
    int dp[101][101][201];
    int f(int i, int j, int k, string &s1, string &s2, string &s3) {
        int n = s1.size(), m = s2.size(), p = s3.size();
        if(k == p and i == n and j == m)
            return true;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        bool flag = false;
        
        if(i < n and j < m and k < p and s1[i] == s3[k] and s2[j] == s3[k]) {
            flag = f(i + 1, j, k + 1, s1, s2, s3) or f(i, j + 1, k + 1, s1, s2, s3);
        }
        else if(i < n and k < p and s1[i] == s3[k]) {
            flag = flag or f(i + 1, j, k + 1, s1, s2, s3);
        }
        else if(j < m and k < p and s2[j] == s3[k]) {
            flag = flag or f(i, j + 1, k + 1, s1, s2, s3);
        }
        
        return dp[i][j][k] = flag;
        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        
        return f(0, 0, 0, s1, s2, s3);
    }
};