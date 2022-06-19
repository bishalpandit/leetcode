class Solution {
    int next(int n) {
        int sum = 0;
        while(n) {
            sum += (n%10) * (n%10); //
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int fast, slow;
        fast = next(n);
        slow = n;
        
        while(fast != 1 and slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        
        return fast == 1;
    }
};
