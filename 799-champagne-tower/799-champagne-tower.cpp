class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(102, vector<double>(102, 0.0));
        
        dp[0][0] = poured;
        
        for(int row=0; row<=query_row; row++)
            for(int col=0; col<=row; col++) {
                double q = (dp[row][col] - 1)/2;
                
                if(q > 0) {
                    dp[row+1][col] += q;
                    dp[row+1][col+1] += q;
                }
            }
        
        cout << dp[query_row][query_glass];
        if(dp[query_row][query_glass] > 1.00) 
            return 1.00;
        else
            return dp[query_row][query_glass];
    }
};