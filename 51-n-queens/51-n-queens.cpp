class Solution {
    
    bool canPlace(vector<string> &board, int r, int c, int n) {
        bool leftDiag(true), rightDiag(true), up(true);
        
        for(int ri = r - 1, ci = c - 1; ri >= 0 and ci >= 0; ri--, ci--)
            if(board[ri][ci] == 'Q')
                leftDiag = false;
        
        for(int ri = r - 1, ci = c + 1; ri >= 0 and ci < n; ri--, ci++)
            if(board[ri][ci] == 'Q')
                rightDiag = false;
        
        for(int ri = r - 1; ri >= 0; ri--)
            if(board[ri][c] == 'Q')
                up = false;
        
        if(up and leftDiag and rightDiag)
            return true;
        return false;
    }
    
    void f(int r, vector<string> &board, vector<vector<string>> &res, int n) {
        if(r == n) {
            res.push_back(board);
            return;
        }
        
        for(int c = 0; c < n; c++) {
               if(canPlace(board, r, c, n)) {
                    board[r][c] = 'Q';
                    f(r + 1, board, res, n);
                    board[r][c] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        
        f(0, board, res, n);
        return res;
    }
};

/*


*/