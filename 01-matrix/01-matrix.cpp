class Solution {
    bool inside(int i, int j, int m, int n) {
        if(i >= 0 and i<m and j>=0 and j<n) return true;
        return false;
    }
    
    int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {// 0-cells will always have 0 distance
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        
         while(!q.empty()) {
            int size = q.size();

            for(int i=0; i<size; i++) {
                
                auto [x, y] = q.front(); q.pop();
        
                for(int j=0; j<4; j++) {
                    int newX = x + dir[j][0], newY = y + dir[j][1];
                    
                    if(inside(newX, newY, m, n)) {
                       
                        if(dist[newX][newY] > dist[x][y] + 1) {
                            dist[newX][newY] = dist[x][y] + 1;
                            q.push({newX, newY});
                        }
                                
                    }
                }
            }
            
        }
        
        return dist;
    }
};
/*


*/