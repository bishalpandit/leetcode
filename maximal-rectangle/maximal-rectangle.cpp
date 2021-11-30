class Solution {
    int maxAreaForEachRow(vector<int> hist) {
        int n = hist.size();
        vector<int> prevSmaller(n), nextSmaller(n);
        
        stack<int> s;
        
        for(int i=0; i<n; i++) {
            
            while(s.size() and hist[i] <= hist[s.top()])
                s.pop();
            
            if(s.size())
                prevSmaller[i] = s.top() + 1;
            else
                prevSmaller[i] = 0;
            
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        for(int i=n-1; i>=0; i--) {
            
            while(s.size() and hist[i] <= hist[s.top()]) // the ones popping 
                s.pop();                                // are being included
            
            if(s.size())
                nextSmaller[i] = s.top() -1 ;
            else
                nextSmaller[i] = n - 1;
            
            s.push(i);
        }
        
        int maxArea(0);
        
        for(int i=0; i<n; i++) {
            maxArea = max(maxArea, (hist[i]*(nextSmaller[i] - prevSmaller[i] + 1)));
        }
        cout << maxArea << " ";
        return maxArea;
        
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() ? matrix.size() : 0;
        if(n == 0)
            return 0;
        int m = matrix[0].size();
        
        vector<int> hist(m,0);
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            
            for(int j=0; j<m; j++) {
                
                if(matrix[i][j] == '1')
                    hist[j] += 1;
                else
                    hist[j] = 0;
            }
            
            ans = max(ans, maxAreaForEachRow(hist));
        }
        
        return ans;
    }
};

//3 1 3 2 2