class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), lo = 0, hi = n - 1;
        int ans = -1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            
            if(nums[mid] == target) {
                ans = mid;
                break;
            }
            
            if(nums[mid] >= nums[0]) {
                if(nums[mid] >= target and target >= nums[0]) 
                    hi = mid - 1;
                else
                    lo = mid + 1;
                
            }
            else {
                if(nums[mid] <= target and target <= nums[n - 1])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        
        return ans;
    }
};