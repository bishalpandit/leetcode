class Solution {
    int dp[5001][2][2];
    int solve(vector<int>& prices, int idx, bool canBuy, bool coolDown) {
        if(idx == prices.size())
            return 0;
        
        if(dp[idx][canBuy][coolDown] != -1)
            return dp[idx][canBuy][coolDown];
        
        int buy = 0, nobuy = 0, sell = 0, nosell = 0, val = prices[idx];
        
        if(canBuy) {
            buy = coolDown ? 0 : (-val + solve(prices, idx + 1, false, false));
            nobuy = solve(prices, idx + 1, true, false);
            return dp[idx][canBuy][coolDown] = max(buy, nobuy);
            }
        else {
            sell = val + solve(prices, idx + 1, true, true);
            nosell = solve(prices, idx + 1, false, false);
            return dp[idx][canBuy][coolDown] = max(sell, nosell);
        }
        
        return 0;
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, true, false);
    }
};
/*

canBuy
coolDown
sell -> gain money +ve
buy -> spend money -ve

int buy = 0, nobuy = 0, sell = 0, nosell = 0;
if(canBuy) {
    buy = cooldown ? 0 : (-val + solve(idx + 1, false, coolDown));
    nobuy = solve(idx + 1, true, false);
    return max(buy, nobuy)
    }
else {
    sell = val + solve(idx + 1, true, true);
    nosell = solve(idx + 1, false, false);
    return max(sell, nosell);
}


*/