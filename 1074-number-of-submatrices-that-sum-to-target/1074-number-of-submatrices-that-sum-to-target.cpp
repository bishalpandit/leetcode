class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = size(matrix), n = size(matrix[0]);
        int ans = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];
        
        for(int i = 0; i < n; i++)
            for(int j = 1; j < m; j++)
                matrix[j][i] += matrix[j - 1][i];
        
        for(int x1 = 0; x1 < m; x1++) // Coordinate 1 - (i, j), Coordinate 2 - (x, y)
            for(int y1 = 0; y1 < n; y1++)
                for(int x2 = x1; x2 < m; x2++)
                    for(int y2 = y1; y2 < n; y2++) {
                        int topLeft = (x1 > 0 and y1 > 0) ? matrix[x1 - 1][y1 - 1]: 0;
                        int topRight = (x1 > 0) ? matrix[x1 - 1][y2] - topLeft: 0;
                        int bottomLeft = (y1 > 0) ? matrix[x2][y1 - 1] - topLeft: 0;
                        
                        int sum = matrix[x2][y2] - topRight - bottomLeft - topLeft;
                        
                        if(sum == target)
                            ++ans;
                    }
        return ans;
    }
};