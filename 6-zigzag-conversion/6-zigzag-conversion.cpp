class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        vector<vector<char>> zigzag;
        int n = s.length(), i = 0;
        int incline = 0;
        
        while(i < n) {
            if(!incline) {
                vector<char> temp(numRows, '*');
                for(int j = 0; j < numRows and i < n; j++)
                    temp[j] = s[i++];
                zigzag.push_back(temp);
            } else {
                while(i < n and incline) {
                    vector<char> temp(numRows, '*');
                    temp[incline] = s[i++];
                    incline--;
                    zigzag.push_back(temp);
                }
                continue;
            }
            incline = numRows - 2;
        }
        
        
        string ans;
        
        for(int i = 0; i < zigzag[0].size(); i++) 
            for(int j = 0; j < zigzag.size(); j++)
                if(zigzag[j][i] != '*')
                ans += zigzag[j][i];
        
        return ans;
        
    }
};
/*

*/