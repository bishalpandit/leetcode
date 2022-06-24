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
        long mx, comp, prev_mx;
        priority_queue<int> pq;
        
        for(auto &ai: t) {
            pq.push(ai);
            sum += ai;
        }
        
        while(true) {
            mx = pq.top(); pq.pop();
            if(mx <= 1) break;
            
            comp = sum - mx;
            if(comp == 1) break;
            
            if(mx < comp or comp == 0 or mx % comp == 0) return false;
            
            prev_mx = mx % comp;
            sum = prev_mx + comp;
            pq.push(prev_mx);
        }
        
        return true;
    }
};