class Solution {
    bool outside(int j, int n) {
        if(j == n or j < 0) return true;
        
        return false; 
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        
        for(int _ = 0; _ < n; _++) { 
            int i = 0, j = _;
            
            while(true) {
                
                if(i == m) {
                    ans[_] = j;
                    break;
                }
                if(grid[i][j] == 1) {
                    if(outside(j + 1, n) or (!outside(j + 1, n) and grid[i][j + 1] == -1))
                        break;
                    else
                       i++, j++;
                }
                else {
                    if(outside(j - 1, n) or (!outside(j - 1, n) and grid[i][j - 1] == 1))
                        break;
                    else
                        i++, j--;
                }
            }
        }
        
        return ans;
    }
                       
};

/*

Stuck if
V shaped pattern
Hits the wall

if(grid[i][j] == 1)
    if(outside(i + 1, j+1) or grid[i][j + 1] == -1)
        -1
    else
        
        
*/