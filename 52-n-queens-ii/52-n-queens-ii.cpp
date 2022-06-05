class Solution {
    bool canPlace(vector<vector<bool>> &board, int r, int c, int n) {
        for(int ri = r - 1; ri >= 0; ri--)
            if(board[ri][c])
                return false;
        for(int ri = r - 1, ci = c - 1; ri >= 0 and ci >= 0; ri--, ci--)
            if(board[ri][ci])
                return false;
        for(int ri = r - 1, ci = c + 1; ri >= 0 and ci < n; ri--, ci++)
            if(board[ri][ci])
                return false;
        
        return true;
    }
    int f(vector<vector<bool>> &board, int r, int n) {
        if(r == n)
            return 1;
        
        int ways = 0;
        
        for(int c = 0; c < n; c++) 
            if(canPlace(board, r, c, n)) {
                board[r][c] = true;
                ways += f(board, r + 1, n);
                board[r][c] = false;
            }
        
        return ways;
    }
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        
        return f(board, 0, n);
    }
};