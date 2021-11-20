class Solution {
    bool isLeft(int mid, vector<int> &nums) {
        return ((mid&1 and (nums[mid]^nums[mid-1]) == 0) 
        or (!(mid&1) and (nums[mid]^nums[mid+1]) == 0)) ? true : false;
    }
    
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            isLeft(mid, nums) ? lo = mid + 1 : hi = mid;
        }
        
        return nums[lo];
    }
};
               
// 1 1 2 2 3 3 4 5 5 6 6
// 0 1 2 3 4 5 6 7 8 9 10
// even - dup at mid + 1, odd - dup at mid - 1 left of bp
// even - dup at mid - 1, odd - dup at mid + 1, right of bp

// 1 1 2 3 3
// 0 1 2 3 4
// Modified binary search - If low and high meet, we should stop. If lo = 5,  hi = 6. mid will always be 5. To generalize, if we have n and n+1, then mid will always be n. So, if we do lo = mid, we will get stuck in inf loop. So, do hi = mid, as hi will change from 6 to 5 and lo and high meet and we stop. But in case of lo = mid, lo will change from 5 to 5 and hence inf loop.
