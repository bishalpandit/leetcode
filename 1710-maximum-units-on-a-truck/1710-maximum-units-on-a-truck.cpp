class Solution {
    static bool comp(vector<int> &box1, vector<int> &box2) {
        return box1.back() > box2.back();
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int maxUnits = 0;
        
        for(auto &item: boxTypes) {
            int boxesTaken = min(truckSize, item[0]);
            truckSize -= boxesTaken;
            maxUnits += boxesTaken * item[1];
            if(!truckSize) return maxUnits;
        }
        
        return maxUnits;
    }
};