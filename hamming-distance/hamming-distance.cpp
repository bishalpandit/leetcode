class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int cnt = 0;
        
        int Xor = x^y;
        if(Xor == 0)
            return 0;
        
        while(Xor) Xor = Xor & Xor - 1, cnt++;
        
        return cnt;
    }
};

// 1111