class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
       int m = matrix.size(),n = matrix[0].size();
        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                matrix[j][i] += matrix[j-1][i];
        for(int i=0;i<m;i++)
            for(int j=1;j<n;j++)
                matrix[i][j] += matrix[i][j-1];
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                for(int k = i;k<m;k++)
                    for(int w = j;w<n;w++)
                    {
                        int topleft =((i>0 && j>0)?matrix[i-1][j-1]:0);
                        int topright = ((i>0)?matrix[i-1][w] - topleft:0);
                        int bottomleft = ((j>0)?matrix[k][j-1] - topleft:0);
                        int sum = matrix[k][w] - topleft - topright - bottomleft;
                        if(sum==target)
                            ++ans;
                    }
        return ans;
    }
};