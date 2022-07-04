class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);
        
        for(int i = 1; i < n; i++) { // Check for left neighbor
            if(ratings[i] > ratings[i - 1])
                left[i] = 1 + left[i - 1];
        }
         
        for(int i = n - 1; i > 0; i--) { // Check for right neighbor
            if(ratings[i - 1] > ratings[i]) {
                right[i - 1] = 1 + right[i];
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) 
            ans += max(left[i], right[i]);
        
        return ans;
    }
};