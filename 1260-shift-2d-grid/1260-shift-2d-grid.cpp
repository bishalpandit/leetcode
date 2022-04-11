class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int i = 0; i < m*n; i++) {
            int r = i/n, c = i%n;
            int newR = (r + (c + k)/n)%m, newC = (c + k)%n;
            ans[newR][newC] = grid[r][c];
        }
        
        return ans;
    }
};
