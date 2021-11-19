class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int cnt = 0;
        
        int Xor = x^y;
        if(Xor == 0)
            return 0;
        int noOfBits = log2(Xor);
        
        for(int i=0; i<=noOfBits; i++) {
            
            if(1&Xor) cnt++;
            Xor >>= 1;
        }
        
        return cnt;
    }
};

// 1111