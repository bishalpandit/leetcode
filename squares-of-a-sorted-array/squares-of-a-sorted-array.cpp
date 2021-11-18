class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        for(int i=0, j=n-1; i<=j;) {
            
            if(abs(nums[i]) >= abs(nums[j])) {
                res[--n] = nums[i]*nums[i];
                i++;
            }
            
            else {
                res[--n] = nums[j]*nums[j];
                j--;
            }
        }
        
        return res;
    }
};

// -4 -1 0 3 10
//      ji
//  0  1  9  16 100