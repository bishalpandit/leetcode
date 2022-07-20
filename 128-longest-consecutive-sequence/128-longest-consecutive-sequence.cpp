class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int n = nums.size(), ans = 0;
        
        
        unordered_set<int> present, vis;
        
        for(auto &ai: nums)
            present.insert(ai);
        
        for(auto &ai: nums) {
            if(!vis.count(ai)) {
                int l = 0, r = 0;
                int numL = ai - 1, numR = ai + 1;
                
                while(present.count(numL)) {
                    vis.insert(numL);
                    numL--;
                    l++;
                }
                
                while(present.count(numR)) {
                    vis.insert(numR);
                    numR++;
                    r++;
                }
                
                ans = max(ans, l + r + 1);
                
            }
        }
    
        return ans;
    }
};