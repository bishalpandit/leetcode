class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> timeToReach; int n = position.size();
        for(int i = 0; i < n; ++i) timeToReach[-position[i]] = ((double)(target - position[i])/speed[i]);
        
        double cur = 0; int ans = 0;
        for(auto &[f,s]: timeToReach)
            if(s > cur) cur = s, ans++;
        
        return ans;
    }
};
/*
1 1 12 7 3
*/