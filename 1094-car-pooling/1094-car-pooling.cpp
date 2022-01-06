class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int availSeats, n = trips.size();
        sort(trips.begin(), trips.end(), 
        [&](vector<int> &v1, vector<int> &v2) { return v1[1] < v2[1]; });
        
        availSeats = capacity;
        
        priority_queue<tuple<int,int,int>> pq;
        
        for(int i=0; i<n; i++) {
            
            while(!pq.empty() and -get<0>(pq.top()) <= trips[i][1]) {
                int no_of_pass = get<2>(pq.top());
                availSeats += no_of_pass;
                pq.pop();
            }
            
            pq.push(make_tuple(-trips[i][2],trips[i][1],trips[i][0]));
            
            availSeats -= trips[i][0];
            cout << availSeats << " ";
            
            if(availSeats < 0)
                return false;
            
        }
        
        
        return true;
    }
};
/*

*/