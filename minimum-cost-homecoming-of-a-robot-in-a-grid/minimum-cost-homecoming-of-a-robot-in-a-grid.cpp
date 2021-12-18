class Solution {
    
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int min_cost = 0, x1 = startPos[0], x2 = homePos[0], y1 = startPos[1], y2 = homePos[1];
        
        while(x1 != x2) {
            x1 += (x2 - x1)/abs(x2 - x1); // x1 > x2 or x1 < x2, we might need to up or down 
            min_cost += rowCosts[x1];       // depending upon position of start and home coords.
        }
        
        while(y1 != y2) {
            y1 += (y2 - y1)/abs(y2 - y1);
            min_cost += colCosts[y1];
        }
        
        return min_cost;
    }
};