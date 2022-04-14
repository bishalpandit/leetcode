class Solution {

    bool isSumOkay(int k, vector<int>& nums, int target) {
        int sum = 0;
        
        for(int i=0; i<k; i++) {
            sum += nums[i];
        }
        
        if(sum >= target) return true;
        
        for(int i=k; i<nums.size(); ++i) {
            sum += nums[i];
            sum -= nums[i-k];
            
            if(sum >= target)
                return true;
        }
        
        return false;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n;
        
        
        
        while(lo < hi) {
            int mid = (lo + hi)/2;
            
            if(isSumOkay(mid, nums, target)) {
                hi = mid;
            }
            else
                lo = mid + 1;
        }
        
        if(!isSumOkay(lo, nums, target)) 
            return 0;
        else
            return lo;
    }
};

    
    