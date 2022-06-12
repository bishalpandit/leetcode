class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        
        int ans = 0, score = 0, l = 0 , r = 0, n = nums.size();
        
        while(l <= r and r < n) {
            
            while(l <= r and s.find(nums[r]) != s.end()) {
                s.erase(nums[l]);
                 score -= nums[l];
                l++;
            }
            
            s.insert(nums[r]);
            score += nums[r];
            r++;
            ans = max(ans, score);
        }
        
        return ans;
    }
};