class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        
        for(int i=0; i<n; i++) {
            while(!s.empty() and s.top() < abs(asteroids[i]) and s.top() > 0 and asteroids[i] < 0) {
                s.pop();
            }
            if(!s.empty() and s.top() >= abs(asteroids[i]) and s.top() > 0 and asteroids[i] < 0) {
                if(s.top() > abs(asteroids[i])) continue;
                
                s.pop();
                continue;
            }
            s.push(asteroids[i]);
        }
        
        vector<int> ans;
        
        while(!s.empty()) {
            ans.push_back(s.top()); s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//4 -2 4 -5 -8 10