class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), moves = 0;
        
        sort(begin(nums), end(nums));
        
        for(auto &num: nums)
            moves += (num - nums[0]);
        
        return moves;
    }
};