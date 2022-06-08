class Solution {

public:
    int removePalindromeSub(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return t == s ? 1 : 2;
    }
};

/*
abbaaba
aabbba
bababb
bbaaaa

*/