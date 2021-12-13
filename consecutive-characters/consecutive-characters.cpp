class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        
        int maxCnt = 1;
        int cnt = 1;
        
        for(int i=0; i<n-1; i++) {
            
            if(s[i] == s[i+1]) {
                cnt++;
                maxCnt = max(maxCnt, cnt);
            }
            else
                cnt = 1;
        }
        
        return maxCnt;
    }
};