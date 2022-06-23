class Solution {
    string f(vector<string>& strs, int lo, int hi) {
        if(lo == hi) return strs[lo];
        int x = (lo + hi)/2;
        
        string left = f(strs, lo, x); 
        string right = f(strs, x + 1, hi);
        return commonPrefix(left, right);
    }
    
    string commonPrefix(string left, string right) {
        string temp;
        
        for(int i = 0; i < left.size() and i < right.size(); i++) {
            if(left[i] != right[i])
                return temp;
            temp += left[i];
        }
        
        return temp;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        return f(strs, 0, n - 1);
    }
};

/*
fl, flow, flock,  flower, fluent

*/