class Solution {
    
    bool inside(int i, int j, int m, int n) {
        if(i >= 0 and i<m and j >= 0 and j<n) return true;
        return false;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int m, int n, int newColor, vector<vector<bool>>& vis, vector<pair<int,int>>& dir, int startColor) {

        vis[sr][sc] = true;
        image[sr][sc] = newColor;
        for(int i=0;i<4;i++) {
            
            int newX = sr + dir[i].first; int newY = sc + dir[i].second;
            
            if(inside(newX,newY,m,n) and !vis[newX][newY] and image[newX][newY] == startColor) 
                dfs(image,newX,newY,m,n,newColor,vis,dir,startColor);
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size() == 0)
            return image;
        
        int m = image.size();
        int n = image[0].size();
        
        int startColor = image[sr][sc];
        
        vector<vector<bool>> vis(m,vector<bool>(n));
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        dfs(image,sr,sc,m,n,newColor,vis,dir,startColor);
        return image;
    }
};