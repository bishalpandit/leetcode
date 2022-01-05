class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        int n = candyType.size();
        
        for(auto &val: candyType)
            s.insert(val);
        
        if(s.size() <= (n/2)) {
            return s.size();
        }
        
        else {
            return n/2;
        }
    }
};

/**

orange: 1, lemon:2, strawberry: 3, mango: 4
n : even
max diff. candies
2 2 2 2 3 3
*/ 