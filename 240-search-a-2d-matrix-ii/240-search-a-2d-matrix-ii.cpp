class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        int r = 0, c = n - 1;
        
        while(r < m and c >= 0) {
            if(matrix[r][c] == target)
                return true;
            else if(target > matrix[r][c])
                r++;
            else
                c--;
        }
        
        return false;
    }
};