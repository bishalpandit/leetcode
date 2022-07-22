class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, ans = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            if(curSum < 0)
                curSum = 0;
            curSum +=  nums[i];
            ans = max(ans, curSum);
        }
        
     return ans;   
    }
};