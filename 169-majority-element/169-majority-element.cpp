class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        return nums[n/2];
    }
};

/*
1 3 2 3 3
1 2 3 3 3
1 2 1 1 2 1 1
1 1 1 22 2
*/