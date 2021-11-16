// TC - O(log(m+n)*m*logn)
// SC - O(1)
class Solution {
    int noOfSmallerElements(int guess, int m, int n) {
        int cnt = 0;
        
        for(int i=1; i<=m; i++) {
            
            int ans = 0;
            int lo = i, hi = i*n;
            
            while(lo <= hi)   {
                
                int mid = lo + (hi - lo)/2;
                
                if(mid <= guess) {
                    ans = mid;
                    lo = mid + 1;
                }
                
                else
                    hi =  mid - 1;
                    
            }
           // cout << ans << " ";
            cnt = cnt + (ans/i);
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


