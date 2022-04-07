class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &val: stones)
            pq.push(val);
        
        
        while(pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            if(x != y)
                pq.push(y - x);
        }
        
        if(pq.empty())
            return 0;
        else 
            return pq.top();
    }
};