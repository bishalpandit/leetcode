class Solution {
    bool isPalindrome(int start, int end, string& s) {
        
        while(start <= end) {
            if(s[start] != s[end])
                return false;
            start++; end--;
        }
        
        return true;
    }
    
    void solve(string s, vector<vector<string>> &ans, vector<string> &temp, int start) {
        if(start == s.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(int end=start; end<s.size(); end++) {
            
            if(isPalindrome(start, end, s)) {
                temp.push_back(s.substr(start, end - start + 1));
                solve(s, ans, temp, end + 1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, ans, temp, 0);
        return ans;
    }
};

/*
acac
a|c|a|c
aca|c
a|cac
*/