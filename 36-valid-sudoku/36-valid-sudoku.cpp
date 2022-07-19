class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> freq(10, 0);
        
        for(int i = 0; i < 9; i++) {
            freq = vector<int>(10, 0);
            
            for(int j = 0; j < 9; j++) {
                if(board[j][i] >= 48 and board[j][i] < 58) {
                      freq[board[j][i] - 48]++;
                
                    if(freq[board[j][i] - 48] > 1)
                    return false;
                }
            }
        }
        
        for(int i = 0; i < 9; i++) {
            freq = vector<int>(10, 0);
            
            for(int j = 0; j < 9; j++) {
                if(board[i][j] >= 48 and board[i][j] < 58) {
                    freq[board[i][j] - 48]++;
                
                    if(freq[board[i][j] - 48] > 1)
                        return false;
                }
            }
        }
        
        
        
        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3) {
                freq = vector<int>(10, 0);
                
                for(int x = i; x < i + 3; x++)
                    for(int y = j; y < j + 3; y++) {
                        if(board[x][y] >= 48 and board[x][y] < 58) {
                            freq[board[x][y] - 48]++;
                
                        if(freq[board[x][y] - 48] > 1)
                            return false;
                        }
                    }
            }
        
        return true;
        
    }
};