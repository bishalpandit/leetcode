class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        int lo = 1, hi = n-2;
        
        if(n >= 2 and nums[0] > nums[1])
            return 0;
        
        if(n >= 2 and nums[n-2] < nums[n-1])
            return n-1;
        
        while(lo <= hi) {
            int guess = lo + (hi - lo)/2;
            if(nums[guess] > nums[guess-1] and nums[guess] > nums[guess+1])
                return guess;
            else if(nums[guess] > nums[guess-1])
                lo = guess + 1;
            else
                hi = guess - 1;
        }
        
        return 0;
    }
};