class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0;
        for(; i < n - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if(diff <= 0) continue;
            pq.push(diff);
            if(pq.size() > ladders) {
                int min = pq.top(); pq.pop();
                if(bricks - min >= 0)
                    bricks -= min;
                else
                    break;
            }
        }
        
        return i;
    }
};
/*
3 7 4 2 5 

*/