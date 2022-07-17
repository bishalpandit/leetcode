class Solution {

public:
    int minOperations(vector<int>& nums, vector<int>& nums2) {    
        map<int, int> m;
        
        int gcdAll = nums2[0];
        
        for(auto &num: nums2)
            gcdAll = __gcd(num, gcdAll);
        
        for(auto &ai: nums)
            m[ai]++;
        
        cout << gcdAll;
        
        int possible = false;
        int res = 0;
        
        for(auto &[f, s]: m) {
            if(gcdAll%f != 0)
                res += s;
            else {
                possible = true;
                break;
            }
        }
        
        return possible ? res : -1;
    }
};