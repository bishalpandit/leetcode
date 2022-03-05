class Solution {
    bool isOutside(int i, int j, int m, int n) {
        return (i < 0 or i == m or j < 0 or j == n);
    }
    
    void CheckFirstDirec(char firstChar, bool &isPossibleOut, int i, int j, int m, int n) {
         switch(firstChar) {
            case 'L': 
                if(isOutside(i, j-1, m, n))
                    isPossibleOut = true;
                break;
            case 'R': 
                if(isOutside(i, j+1, m, n))
                    isPossibleOut = true;
                break;
            case 'U': 
                if(isOutside(i-1, j, m, n))
                    isPossibleOut = true;
                break;
            case 'D': 
                if(isOutside(i+1, j, m, n))
                    isPossibleOut = true;
                break;
        }
    }
    
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void dfs(vector<vector<int>> &grid, int i, int j, bool &isPossibleOut, vector<vector<int>> &vis, char checkDir) {
        int m = grid.size(), n = grid[0].size();
        
        vis[i][j] = 1;
        
       CheckFirstDirec(checkDir, isPossibleOut, i, j, m , n);
        if(isPossibleOut) {
            grid[i][j] = 0;
        }
        
        for(int k=0; k<4; k++) {
            int newi = i + dirs[k].first, newj = j + dirs[k].second;
            
            if(!isOutside(newi, newj, m, n) and grid[newi][newj] == 1 and !vis[newi][newj]) {
                dfs(grid, newi, newj, isPossibleOut, vis, checkDir);
                if(isPossibleOut)
                    grid[i][j] = 0;
            }
            
            if(isOutside(newi, newj, m, n)) {
                isPossibleOut = true;
                grid[i][j] = 0;
            }
            
        }
        
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        bool isPossibleOut = false;
        
        for(int i=0; i<n; i++) {
          
                if(grid[0][i] == 1 and !vis[0][i])  {
                    dfs(grid, 0, i, isPossibleOut, vis, 'U');
                    isPossibleOut = false;
                }
                
                if(grid[m-1][i] == 1) {
                    dfs(grid, m-1, i, isPossibleOut, vis, 'D');
                    isPossibleOut = false;
                }
        }
        
        isPossibleOut = false;
        for(int i=0; i<m; i++) {
          
                if(grid[i][0] == 1) {
                    dfs(grid, i, 0, isPossibleOut, vis, 'L');
                    isPossibleOut = false;
                }
                
                if(grid[i][n-1] == 1) {
                    dfs(grid, i, n-1, isPossibleOut, vis, 'R');
                    isPossibleOut = false;
                }
        }
        
        for(auto row: grid) {
            for(auto val: row)
                cout << val << " ";
            cout << '\n';
        }
        int ansCnt = 0;
        
        for(auto row: grid)
            for(auto val: row)
                if(val == 1)
                    ansCnt++;
        
        return ansCnt;
    }
};

// move -> to adj land cell or walk off the grid
// ans -> no. of land cells from which we cannot walk out of the grid for any **moves**

/*

0000
0000
0000
0100
00*0
0000

loop and call for each land(1)
isOutPossible = false,
If we can move out, make isOutPossible = true, and now make the cells which are reachable 0 as they are affected also in a contagious way.
the ones not affected will be as 1, and finally we count the ones
Solved!
if no special or edge cases...
*/