class Solution {
    vector<int> dir{1, 0, -1, 0, 1};
    
    bool inside(vector<vector<char>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        return i >= 0 and i < m and j >=0 and j < n;
    }
    
    void bfs(int i, int j, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        
        q.push({i, j});
        grid[i][j] = '0';
        
        while(q.size()) {
            int x, y;
            tie(x, y) = q.front(); q.pop();
            
            for(int i = 0; i < 4; i++) {
                int newX = x + dir[i], newY = y + dir[i + 1];
                if(inside(grid, newX, newY) and grid[newX][newY] == '1') {
                    grid[newX][newY] = '0';
                    q.push({newX, newY});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int ans = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '1') {
                    ans++;
                    bfs(i, j, grid);
                }
        
        return ans;
    }
};
