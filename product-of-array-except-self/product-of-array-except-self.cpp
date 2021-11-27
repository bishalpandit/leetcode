class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =  nums.size();
        vector<int> prefix(n), suffix(n), ans(n);
        
        prefix[0] = nums[0], suffix[n-1] = nums[n-1];
        
        // build prefix product array
        for(int i=1;i<n;i++) {
            prefix[i] = nums[i]*prefix[i-1];
        }
        
        // build suffix product array
        for(int i=n-2;i>=0;i--) {
            suffix[i] = nums[i]*suffix[i+1];
        }
        
        ans[0] = suffix[1], ans[n-1] = prefix[n-2];
        
        // Build the answer vector using pre and suf vector
        for(int i=1;i<n-1;i++) {
            ans[i] = prefix[i-1]*suffix[i+1];
        }
        
        return ans;
    }
};


//  1    2    6  24 --   left
//  24  24   12   4 --   right

//  left[i-1]*right[i+1]