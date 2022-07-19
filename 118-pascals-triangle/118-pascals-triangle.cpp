class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            vector<int> cur;
            
            for(int j = 0; j <= i; j++) 
                if(j == 0 or j == i)
                    cur.push_back(1);
                else
                    cur.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);    
            
            ans.push_back(cur);
        }
        
        return ans;
    }
};

/*
1
1 1
1 2 1
1 3 3 1

TC - O(n^2)
SC - O(1)
*/