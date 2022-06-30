class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        
        for(auto &vec: grid)
            for(auto &num: vec)
                v.push_back(num);
        
        sort(begin(v), end(v));
        
        int n = v.size(), moves(0);
        int median = v[n/2];
        
        for(auto &num: v) {
            int y = abs(num - median);
            if(y%x)
                return -1;
            moves += y/x;
        }
        
        return moves;
    }
};