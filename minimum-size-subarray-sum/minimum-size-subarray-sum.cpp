class Solution {
    int getSubSum(int curLen, vector<int>& nums, int &target) {
        int k = curLen, n = nums.size();
        int curSum = 0;
        
        for(int i=0; i<k; i++)
            curSum += nums[i];
        
        int maxSum = curSum;
        
        for(int i=k; i<n; i++) {
            
            int left = nums[i-k];
            int right = nums[i];
            
            curSum = curSum + right - left;
            maxSum = max(maxSum, curSum);
        }
        cout << maxSum << " ";
        return maxSum >= target;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n+1;
        bool isValid;
        int mid;
        while(lo < hi) {
            mid = lo + (hi - lo)/2;
            isValid = getSubSum(mid, nums, target);
            if(isValid)
                hi = mid;
            else
                lo = mid + 1;
        }
        
        if(lo > n)
            return 0;
        else
            return lo;
    }
};

// 0 3
// 4 3 3 2 2 1