class Solution {
    int findMax(map<char, int> &freq) {
        int mx = 0;
        
        for(auto &[f, s]: freq)
            mx = max(mx, s);
        
        return mx;
    }
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        
        int st = 0, end = 0;
        
        map<char, int> freq;
        
        int diff = 0, ans = 0, maxFreq;
        
        while(st <= end and end < n) {
            
                freq[s[end]]++;
                maxFreq = findMax(freq);
                diff = (end - st + 1) - maxFreq; 
                if(diff <= k)
                    ans = max(ans, end - st + 1);
            
            
            while(diff > k) {
                freq[s[st]]--;
                maxFreq = findMax(freq);
                st++;
                diff = (end -  st + 1) - maxFreq;
            }
            
            end++;
        }
        
        return ans;
    }
};