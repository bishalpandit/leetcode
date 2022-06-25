class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return true;
        int cnt = 1;
        bool way1 = true, way2 = true;
        
        vector<int> nums2 = nums;
        
        for(int i = 0; i < n - 1; i++) {
            if(nums2[i] > nums2[i + 1]) {
                cnt--;
                nums2[i + 1] = nums2[i];
            }
            
            if(cnt < 0) {
                way1 = false;
                break;
            }
        }
        
        cnt = 1;
        for(int i = n - 1; i > 0; i--) {
            if(nums[i - 1] > nums[i]) {
                cnt--;
                nums[i - 1] = nums[i];
            }
            if(cnt < 0) {
                way2 = false;
                break;
            }
        }
        
        return way2 or way1;
    }
};

/*

4 2 3

2 4 7 13 13 24

2 4 7 5 6 

2 4 6 7 5

6 6 6 6 6

n <= 2 true

4 2 2

*/