class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        
        vector<int> up(n), down(n);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    up[i] = max(up[i], down[j] + 1);
                }
                else if(nums[i] < nums[j]) {
                    down[i] = max(down[i], up[j] + 1);
                }
            }
        }
        
        return 1 + max(down[n - 1], up[n - 1]);
    }
};