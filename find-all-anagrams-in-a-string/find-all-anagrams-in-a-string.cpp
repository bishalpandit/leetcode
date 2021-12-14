class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size(), n = s.size();
        
        if(n < k)
            return {};
        
        vector<int> ans;
        
        map<char, int> m1, m2;
        
        for(int i=0; i<k; i++)
            m1[s[i]]++;
        
        for(auto &ch: p)
            m2[ch]++;
        
        if(m1 == m2)
            ans.push_back(0);
        
        for(int i=k; i<n; i++) {
              
            char start = s[i-k], end = s[i];
            
            m1[start]--;
            if(m1[start] == 0)
                m1.erase(start);
            m1[end]++;
            
            if(m1 == m2)
                ans.push_back(i-k+1);
            
        }
        
        return ans;
    }
};

// ab aab