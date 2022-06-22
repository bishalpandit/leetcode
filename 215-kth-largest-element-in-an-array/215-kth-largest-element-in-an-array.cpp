class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size())
            return -1;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto &val: nums) {
            pq.push(val);
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
    }
};

/*
3 3 3 4 4 5

4 4 5
*/