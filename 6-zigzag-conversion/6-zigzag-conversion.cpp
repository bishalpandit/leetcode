class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        vector<string> ans(min(numRows, (int)s.length()));
        int rowNo = 0, goingDown = false;
        
        for(auto &c: s) {
            ans[rowNo] += c;
            if(rowNo == 0 or rowNo == numRows - 1) goingDown= !goingDown;
            rowNo += goingDown ? 1 : -1; 
        }
        
        string res;
        
        for(auto &str: ans)
            res += str;
        
        return res;
    }
};
/*
p    
a
y
*/