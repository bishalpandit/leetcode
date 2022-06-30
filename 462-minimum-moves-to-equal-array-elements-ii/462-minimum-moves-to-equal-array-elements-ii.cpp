class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), moves(0);
        
        sort(begin(nums), end(nums));
        
        int median = nums[n/2];
        
        for(auto &num: nums)
            moves += abs(median - num);
        
        return moves;
    }
};