class Solution {
public:
    int maxArea(vector<int>& height) {
            
        int area = 0, n = height.size();
        
        int i = 0, j = n - 1;
        
        while(i <= j) {
            area = max(area, min(height[i], height[j])*(j-i));
            height[i] >= height[j] ? j-- : i++;
        }
        
        return area;
    }
};

// max