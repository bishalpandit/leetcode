class Solution {
public:
    int largestRectangleArea(vector<int>& hist) {
        int n = hist.size();
        
        stack<int> s;
        int maxArea(0);
        
        for(int i=0; i<=n; i++) {
            while(s.size() and (i == n or (hist[s.top()] >= hist[i]))) {
                int nextSmaller = i;
                int height = hist[s.top()]; s.pop();
                int width;
                if(s.empty())
                    width = i;
                else
                    width = i - s.top() - 1;
                maxArea = max(maxArea, height*width);
            }
            s.push(i);
        }
        
        return maxArea;
    }
};

// we will always calculate the area for our stack top element...