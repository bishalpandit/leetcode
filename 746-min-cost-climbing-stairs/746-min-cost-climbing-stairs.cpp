class Solution {
public:
    int minCostClimbingStairs(vector<int>& dp) {
        int n = dp.size();
        
        for(int i = 2; i < n; i++) {
            dp[i] += min(dp[i - 1], dp[i - 2]);
        }
        
        return min(dp[n - 1], dp[n - 2]);
    }
};

/*
10 15 20 _
0  1  2

1 100 1 1 1 100 1 1 100 1  _

*/