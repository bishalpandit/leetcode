class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        return !(n-1&n);
    }
};

// n = 8
// 0111
// 1000