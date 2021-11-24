class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
            
        auto inside = [&](int i, int j) {
            if(i >= 0 and j>=0 and i<m and j<n) return true;
            return false;
        };
        
        auto bfs = [&](int startX, int startY) {
            
            queue<pair<int,int>> q;
    
            q.push({startX,startY});
            grid[startX][startY] = 0;
            int area = 1;
            while(!q.empty()) {
                int X, Y;
                X = q.front().first, Y = q.front().second; q.pop();
                
                for(int i=0;i<4;i++) {
                    int newX = X + dir[i].first, newY = Y + dir[i].second;
                    if(inside(newX,newY) and grid[newX][newY]) {
                        grid[newX][newY] = 0;
                        area++;
                        q.push({newX,newY});
                    }
                }
            }
            return area;
        };
        
        int ans = 0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j])
                    ans = max(ans,bfs(i,j));
            }
        }
        
        return ans;
        
    }
};
