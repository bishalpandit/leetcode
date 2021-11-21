class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        unordered_map<char,int> charMap;
        int maxLen = 0;
        int start = -1;
        for(int end=0; end<n; end++) {
            char ch = s[end];
            
            if(charMap.find(ch) != charMap.end()) {
                start = max(start, charMap[ch]);
            }
            
            charMap[ch] = end;
            maxLen = max(maxLen, end - start);
        }
        
        return maxLen;
    }
};
// abcabcbb
//  pwwkew
//  bbbbb
// ajeryadrynvc
// aa
// aba, abba
// abcd
// abba
// abbbafsf
// pwwkew
// 012345