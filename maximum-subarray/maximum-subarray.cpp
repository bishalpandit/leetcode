class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;
        
        for(int &num: nums) {
            if(curSum < 0)
                curSum = 0;
            curSum += num;
            maxSum = max(maxSum, curSum);
        }
        
        return maxSum;
    }
};