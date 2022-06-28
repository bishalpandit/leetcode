class Solution {
public:
    int minPartitions(string n) {
        int len = n.length();
        int ans = 1;
        
        for(auto &num: n) {
            ans = max(ans, num - 48);
        }
        
        return ans;
    }
};

/*

25

11 11 1 1 1
1
10
11
100
*/