class Solution {
    int i = 0;
public:
    void reverseString(vector<char>& s) {
        if(i == (s.size()/2))
            return;
        swap(s[i],s[s.size()-i-1]);
        i++;
        reverseString(s);
    }
};

/*

h, e, l, l, o

*/