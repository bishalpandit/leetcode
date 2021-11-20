class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int Xor = 0;
        
        for(int i=0; i<n; i++)
            Xor ^= nums[i];
        
        return Xor;
    }
};

 