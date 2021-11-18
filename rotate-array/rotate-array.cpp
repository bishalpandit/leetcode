class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        
        int p = n - k;
        
        vector<int> temp;
        
        for(int i=p; i<n; i++)
            temp.push_back(nums[i]);
        
        for(int i=0; i<p; i++)
            temp.push_back(nums[i]);
        
        for(int i=0; i<n; i++)
            nums[i] = temp[i];
    }
};