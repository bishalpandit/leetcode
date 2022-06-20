class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        unordered_set<string> good(words.begin(), words.end());
        
        for(auto &w: words)
            for(int i = 1; i < w.size(); i++) 
                good.erase(w.substr(i));
        
        int ans = 0;
        
        for(auto &w: good)
            ans += w.size() + 1;
        
        return ans;
    }
};

/*

*/