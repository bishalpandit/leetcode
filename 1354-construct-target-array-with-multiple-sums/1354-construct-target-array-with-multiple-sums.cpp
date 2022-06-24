class Solution {
public:
    bool isPossible(vector<int>& t) {
        int n = t.size();
        
        if(n == 1) {
            if(t[0] == 1)
                return true;
            else
                return false;
        }
        
        long sum = 0;
        int mx, prev_mx;
        
        priority_queue<int> pq;
        
        for(auto &ai: t) {
            pq.push(ai);
            sum += ai;
        }
        
        while(pq.top() != 1) {
            mx = pq.top(); pq.pop();
            
            prev_mx = mx % (sum - mx);
            if(sum - mx == 1) return true;
            if(prev_mx == mx or prev_mx == 0) return false;
            
            sum = sum - mx + prev_mx;
            pq.push(prev_mx);
        }
      
        return true;
    }
};