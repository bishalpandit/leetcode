class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        string ans;
        
        for(auto &w: words)
            reverse(w.begin(), w.end());
        
        sort(words.begin(), words.end());
        
        
        for(int i = 0; i < n - 1; i++) {
            int j = 0;
            
            while(j < words[i].size()) {
                if(words[i][j] != words[i + 1][j]) {
                    ans += words[i] + '#';
                    break;
                }
                j++;
            }
        }
        
        ans += words[n - 1] + '#';
        
        cout << ans;
        
        return ans.size();
    }
};

/*
[ em emit emita]

moneygram#kick
*/