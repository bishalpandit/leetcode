class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1,1);
        vector<int> indices(n+1,-1);
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<n; i++) {
            
            for(int j=0; j<i; j++) {
                
                if(nums[i]%nums[j] == 0) {
                    
                    if((dp[j] + 1) > dp[i]) {
                        dp[i] = dp[j] + 1;
                        indices[i] = j;
                    }
                }
            }
        }
        
        int maxIdx = max_element(dp.begin(), dp.end()) - dp.begin();
        
        vector<int> res;
        
        int i = maxIdx;
        
        while(i != -1) {
            res.push_back(nums[i]);
            i = indices[i];
        }
        
        return res;
    }
};


/*

 
 
If there is a no.(say k) which is not divisible by 'X', it is guranteed that it won't be divisible by multiples of 'X'.

1 2 4 8 16

*/

