class Solution {
    
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length(), len = s2.length();
        if(len < k)
            return false;
        
        map<char,int> pattern;
        
        for(auto &ch: s1)
            pattern[ch]++;
        
        
        map<char,int> substri;
        
        for(int i=0; i<k; i++)
            substri[s2[i]]++;
        
        
        if(pattern == substri)
            return true;
        
        for(int i=k; i<len; i++) {
            char st = s2[i-k], end = s2[i];
            bool valid = true;
            
            substri[end]++;
            substri[st]--;
            
            for(auto [f,s]: pattern)
                if(substri[f] != s)
                    valid = false;
            
            if(valid)
                return true;
            
            
        }
        
        return false;
    }
};


//abcdegfegke
//gefk