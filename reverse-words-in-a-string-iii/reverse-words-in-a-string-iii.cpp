class Solution {
public:
    string reverseWords(string s) {
        size_t len = s.length();
        int wordLen = 0;
        
        for(int cur = 0; cur < len; cur++) {
            
            if(s[cur] == ' ') {
                reverse(s.begin()+cur-wordLen,s.begin()+cur);
                wordLen = 0;
            }
            
            else
                wordLen++;
            
        }
        
        reverse(s.end()-wordLen,s.end());
        
        return s;
    }
};