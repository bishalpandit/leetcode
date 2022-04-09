class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        priority_queue<pair<int,int>> pq;
        map<int, int> freq;
        
        for(int &val: nums)
            freq[val]++;
        
        for(auto &[f, s]: freq) {
            if(pq.size() == k and -pq.top().first < s) {
                pq.pop();
                pq.push({-s, f});
        
            }
            else if(pq.size() < k)
                pq.push({-s,f});
            
        }
        
        vector<int> ans;
        
        while(!pq.empty()) {
            ans.push_back(pq.top().second); pq.pop();
        }
        
        return ans;
    }
};

/*
freq map
PQ -> 6: 1 5:3 4: 2 9:1 7:1
N -> M*logK
*/