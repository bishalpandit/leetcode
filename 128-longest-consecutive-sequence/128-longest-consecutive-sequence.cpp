class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        unordered_set<int> s;
        int ans = 0;
        
        for(auto &num: nums) s.insert(num);
        
        for(auto &num: s) {
            int mn = num - 1, mx = num + 1;
            
            while(s.count(mn)) {
                s.erase(mn);
                mn--;
            }
            
            mn++;
            
            while(s.count(mx)) {
                s.erase(mx);
                mx++;
            }
            
            ans = max(ans, mx - mn);
        }
        
        return ans;
    }
};