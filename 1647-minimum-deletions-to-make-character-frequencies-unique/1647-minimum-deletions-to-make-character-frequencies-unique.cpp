class Solution {

public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        for(auto &c: s)
            m[c]++;
        
        vector<int> freq;
        for(auto &[f, s]: m)
            freq.push_back(s);
        
        sort(begin(freq), end(freq), greater<int>());

        int ans = 0;
        
        for(int i = 1; i < freq.size(); i++) {
            if(freq[i - 1] == 0) { // When last char while traversing has 0 freq.
                ans += freq[i]; 
                freq[i] = 0;
                continue;
            }
            
            if(freq[i - 1] <= freq[i]) {
                ans += max(0, freq[i] - freq[i - 1]) + 1; // Characters need to be removed
                freq[i] = min(freq[i - 1] - 1, freq[i]); // New freq count
            }
        }
        
        return ans;
    }
};

/*

5 4 3 2 1 2
0 2
*/