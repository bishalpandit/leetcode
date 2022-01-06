class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> occupancy(1001, 0); int n = trips.size();
        
        for(int i=0; i<n; i++) {
            occupancy[trips[i][1]] += trips[i][0];
            occupancy[trips[i][2]] -= trips[i][0];
        }
        
        int curCap = 0;
        
        for(int i=0; i<1001; i++) {
            curCap += occupancy[i];
            if(curCap > capacity)
                return false;
        }
        
        return true;
    }
};
/*

*/