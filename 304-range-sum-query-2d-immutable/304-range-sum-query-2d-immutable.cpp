class NumMatrix {
    vector<vector<int>> queryMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        queryMatrix = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        
        for(int i = 0; i < matrix.size(); ++i) 
            for(int j = 0; j < matrix[0].size(); ++j)
                queryMatrix[i][j] = (j == 0) ? matrix[i][j] : 
                queryMatrix[i][j - 1] + matrix[i][j];
        
         for(int i = 0; i < matrix[0].size(); ++i) 
            for(int j = 0; j < matrix.size(); ++j)
                queryMatrix[j][i] = (j == 0) ? queryMatrix[j][i] : 
                queryMatrix[j - 1][i] + queryMatrix[j][i];
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int leftPart = (col1 - 1 < 0) ? 0 : queryMatrix[row2][col1 - 1];
        int upperPart = (row1 - 1 < 0) ? 0 : queryMatrix[row1 - 1][col2];
        int leftUpperPart = (row1 - 1 < 0 or col1 - 1 < 0) ? 0 : queryMatrix[row1 - 1][col1 - 1];
        int sum = queryMatrix[row2][col2] - leftPart - upperPart + leftUpperPart;
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */



