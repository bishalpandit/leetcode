class Solution {
    int sumOfSquareDigits(int n) {
        int sum = 0;
        
        while(n) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        
        s.insert(n);
        
        while(n != 1) {
            n = sumOfSquareDigits(n);
            if(s.count(n))
                return false;
            s.insert(n);
        }
        
        return true;
    }
};

// 7 3 = 49 + 9 58 25 + 64 89 = 64 + 81 = 145 = 1 + 16 + 25 = 50 = 25 = 4 + 25 = 29
// 29 = 4 + 81 = 85 = 64 + 25 