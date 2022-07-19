class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = size(s), n = size(t);
        
        int freqS[26]{0};
        
        for(auto &c: s) freqS[c - 'a']++;
        
        for(auto &c: t) freqS[c - 'a']--;
        
        for(auto &f: freqS)
            if(f != 0)
                return false;
        
        return true;
    }
};

/*
if (s.len != t.len)
    return false;
    
freqS[26]

for i in t
  freq[c - 'a']--;

for i in 26
    if freq[i] != 0
        return false;

return true;
*/