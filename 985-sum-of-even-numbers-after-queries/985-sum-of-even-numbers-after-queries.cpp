class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        
        int sum = 0;
        vector<int> ans;
        
        for(auto &ai: nums)
            if(ai % 2 == 0)
                sum += ai;
        
        for(auto &q: queries) {
            int val = q[0], idx = q[1];
            
            sum -= (nums[idx] % 2 == 0) ? nums[idx] : 0; 
            nums[idx] += val;
            
            if(nums[idx] % 2 == 0) 
                sum += nums[idx];
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};

/*
- queries - 2 2 3 4 | 2 -1 3 4 | -2 -1 3 4 | -2 -1 3 6

evens[ t, t, f, t]
init even sum - 6 -> 8 -> 6 -> 2 -> 4

if cur is odd
  after add if even
    add to sum
if cur is even
 sum -= cur
 after add if even 
   add to sum
*/