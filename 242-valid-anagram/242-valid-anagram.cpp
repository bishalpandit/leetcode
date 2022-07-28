class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = size(s), n = size(t);
        
        unordered_map<char, int> freq;
        
        for(auto &c: s)
            freq[c]++;
        
        for(auto &c: t)
            freq[c]--;
        
        for(auto &[f, s]: freq)
            if(s != 0)
                return false;
        
        return true;
    }
};
