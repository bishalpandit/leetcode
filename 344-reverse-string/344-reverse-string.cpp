class Solution {
    int i = 0;
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if(i == len/2) return;
        
        swap(s[i], s[len-i-1]);
        i++;
        
        reverseString(s);
    }
};

