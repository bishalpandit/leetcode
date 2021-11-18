class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        deque<int> dq;
        
        for(auto &num: nums) {
            dq.push_back(num);
        }
        
        while(k--) {
            int val = dq.back(); dq.pop_back();
            dq.push_front(val);
        }
        
        for(int i=0; i<nums.size(); i++) {
            int val = dq.front(); dq.pop_front();
            nums[i] = val;
        }
    }
};