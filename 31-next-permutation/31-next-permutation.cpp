class Solution {

public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = n-1;
        int i;
        for(i=n-1; i>0; i--) {
            if(nums[i-1] < nums[i]) {
                int rep_pos = i - 1;
                while(nums[rep_pos] >= nums[k]) {
                    k--;
                }
                swap(nums[rep_pos], nums[k]);
                sort(nums.begin() + rep_pos + 1, nums.end());
                break;
            }
        }
        
        if(i == 0) {
            sort(nums.begin(), nums.end());
        }
        
        
    }
};

/*
1 2 3
1 3 2


*/