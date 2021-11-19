class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0 or right == 0)
            return 0;
        
        long And = left;
        
        for(; left<right; left++) {
            And &= left;
           if(And == 0)
               return 0; 
        }
        
        And &=right;
        
        
        return And;
    }
};