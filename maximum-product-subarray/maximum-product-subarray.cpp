class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = INT_MIN, imax = 1, imin = 1;
        
        for(int i=0; i<n; i++) {
            
            if(nums[i] < 0) // when nums[i] is -ve, then imax becomes imin and vice-versa
                swap(imax, imin);
            
            imax = max(imax*nums[i], nums[i]); // max of dp[i-1]*nums[i] and nums[i]
            imin = min(imin*nums[i], nums[i]); // same as above
            
            maxi = max(maxi, imax); // keep updating  your max
        }
        
        return maxi;
    }
};

/*

        2    3   -2   4   -1

imax    2    3    -2   -48     48

imin    2    6    -12  4   -4
*/