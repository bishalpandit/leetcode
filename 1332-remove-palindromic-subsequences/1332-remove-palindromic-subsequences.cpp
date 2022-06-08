class Solution {
    bool is_palindrome(string &s) {
        int l = 0, r = s.size() - 1;
        
        while(l <= r) {
            if(s[l] != s[r])
                return false;
            l++; r--;
        }
        
        return true;
    }
public:
    int removePalindromeSub(string s) {
        return is_palindrome(s) ? 1 : 2;
    }
};

/*
abbaaba
aabbba
bababb
bbaaaa

*/