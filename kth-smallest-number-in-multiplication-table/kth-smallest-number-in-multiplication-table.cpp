// TC - O(log(m+n)*m*logn)
// SC - O(1)
class Solution {
    int noOfSmallerElements(int guess, int m, int n) {
        int cnt = 0;
        
        for(int i=1; i<=m; i++) {
            
            cnt += min(guess/i, n);
        }
        
        return cnt;
    }
public:
    int findKthNumber(int m, int n, int k) {
        
        int lo = 1, hi = m*n;
        int ans = 0;
        
        while( lo <= hi) {
            
            int guess = lo + (hi - lo)/2;
            int cntSmaller = noOfSmallerElements(guess, m, n);
            cout << cntSmaller << " ";
            if(cntSmaller < k ) {
                lo = guess + 1;
            }
            
            else {
                ans = guess;
                hi = guess - 1;
            }
        }
        
        return ans;
    }
};

// 


