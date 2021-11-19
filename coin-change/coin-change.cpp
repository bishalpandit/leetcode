class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int MAX = amount + 1;
        vector<int> dp(amount+1, MAX);
        dp[0] = 0;
        
        for(int amt=1; amt<dp.size(); amt++) {
            for(auto &coin: coins)
                if(coin <= amt)
                    dp[amt] = min(dp[amt], dp[amt - coin] + 1);
        }
        
        return dp[amount] > amount  ? -1 : dp[amount];
    }
};

