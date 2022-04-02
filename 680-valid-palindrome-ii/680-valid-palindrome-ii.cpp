class Solution {
public:
    bool validPalindrome(string s) {
        int delimit = 1;
        
        int len = s.length();
        int i = 0, j = len - 1;
        map<char, int> freq;
        
        for(auto &ch: s)
            freq[ch]++;
        
        for(auto [f, s]: freq)
            cout << f << ": " << s << " ";
        
        while(i <= j) {
            
            if(s[i] != s[j]) {
                if(!delimit) return false;
                
                int noi, noj;
                bool select1 = false;
                
                if(s[i] == s[j-1] and s[i+1] == s[j] ) { 
                    noi = freq[s[i]]; noj = freq[s[j]];
                    cout << noi << s[i];
                    if(noi%2 == 0 and noj%2 != 0) 
                        select1 = true;
                }
                
               if(select1) {
                   if(s[i] == s[j-1]) { delimit--;  freq[s[j-1]]--; freq[s[j]]--; freq[s[i]]--; j-=2; i++; continue; }
                   if(s[i+1] == s[j]) { delimit--;  freq[s[i+1]]--; freq[s[j]]--; freq[s[i]]--; i+=2; j--; continue; }
               }     
                else {
                if(s[i+1] == s[j]) { delimit--;  freq[s[i+1]]--; freq[s[j]]--; freq[s[i]]--; i+=2; j--; continue; }
                    if(s[i] == s[j-1]) { delimit--;  freq[s[j-1]]--; freq[s[j]]--; freq[s[i]]--; j-=2; i++; continue; }
                }

                return false;
            }
            freq[s[j]]--;
            freq[s[i]]--;
            i++; j--;
            
        }
        
        return true;
    }
};
// ab
/*
kadcckda
7
1
race | cakr
freq,
pos,
what matters most? freq, posi, odd/even, at most one, half length, cnt

aba
barok nbaro
aabbcc next char
*/ 