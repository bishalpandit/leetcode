class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int sr = 0, er = m - 1, sc = 0, ec = n - 1;
        vector<int> ans;
        
        while(sr <= er and sc <= ec) {
            for(int i = sc; i <= ec; i++) 
                ans.push_back(mat[sr][i]);
            sr++;
            for(int i = sr; i <= er; i++)
                ans.push_back(mat[i][ec]); 
            ec--;
            if(sr <= er)
                for(int i = ec; i >= sc; i--)
                    ans.push_back(mat[er][i]);
            er--;
            if(sc <= ec)
                for(int i = er; i >= sr; i--)
                    ans.push_back(mat[i][sc]);
            sc++;
        }
        
        return ans;
    }
};

/*
     e s
     1 2 3
     4 5 6
es   7 8 9
     1 2 3
*/