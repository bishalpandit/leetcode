class Solution {
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool inside(int i, int j, int m, int n) {
        return i >= 0 and i < m and j >= 0 and j < n;
    }
    
    int bfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis) {
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        vis[i][j] = true;
        
        bool invalid = false;
        
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            
            if((x-1) < 0 or (x+1) == m or (y-1) < 0 or (y+1) == n )
                invalid = true;
            
            for(int k=0; k<4; k++) {
                int newX = x + dirs[k].first, newY = y + dirs[k].second;
                
                if(inside(newX, newY, m, n) and grid[newX][newY] == 0 and !vis[newX][newY])                 {
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        
        if(invalid)
            return 0;
        return 1;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        int ans = 0;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(!vis[i][j] and grid[i][j] == 0) {
                    ans += bfs(grid, i, j, vis);
                    cout << ans << " ";
                }
            }
        
        return ans;
    }
};