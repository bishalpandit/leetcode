class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(auto &vec: matrix)
            reverse(vec.begin(), vec.end());
        
    }
};


/*
1 2 3 
4 5 6
7 8 9
  |
  V
1 4 7
2 5 8
3 6 9
  |
  V
7 4 1
8 5 2
9 6 3

7 4 1
8 5 2
9 6 3

*/