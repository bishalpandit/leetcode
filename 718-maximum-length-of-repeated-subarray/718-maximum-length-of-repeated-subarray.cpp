class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int> prev(nums2.size()+1, 0), cur(nums2.size()+1, 0);
        int ans = 0;
        
        for(int i=1; i<=nums1.size(); i++) {
            for(int j=1; j<=nums2.size(); j++) {
                if(nums1[i-1] == nums2[j-1]) {
                    cur[j] = prev[j-1] + 1;
                    ans = max(ans, cur[j]);
                }
            }
            fill(prev.begin(), prev.end(), 0);
            swap(prev, cur);
        }
        
        return ans;
    }
};
