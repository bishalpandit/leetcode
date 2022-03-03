class Solution {

    
    string solve(string s,int &i) {
        string ans;
        
        while(i < s.length() and s[i] != ']') {
            
            if(!isdigit(s[i]))
                ans += s[i++];
            
            else {
                int n = 0;
                
                while(i < s.length() and isdigit(s[i])) {
                    n = n*10 + (s[i] - '0');
                    i++;
                }
                i++; // skip [
                
                string temp = solve(s, i);
                
                i++; // skip ]
                
                while(n--) {
                    ans += temp;
                }
            }
        
        }
        
        return ans;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};

