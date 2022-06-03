class Solution {
    int dp[301];
    bool f(string &s, int i, set<string> dict) {
        int n = s.length();
        if(i == n)
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        bool success = false;
        
        for(int j = i; j < n; j++) {
            string str = s.substr(i, j - i + 1);
            if(dict.count(str))
                success = success || f(s, j + 1, dict);
        }
        
        return dp[i] = success;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(auto &wi: wordDict)
            dict.insert(wi);
        
        memset(dp, -1, sizeof(dp));
        return f(s, 0, dict);
    }
};

/*
6 * 10^6

broasthere bro as
*/