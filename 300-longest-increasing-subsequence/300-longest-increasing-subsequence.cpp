class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, 1);
        
        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[j] < nums[i]) {
                    cache[i] = max(cache[i], cache[j] + 1);
                }
            }
        }
        
        int ans = *max_element(cache.begin(), cache.end());
    
        return ans;
    }
    
};