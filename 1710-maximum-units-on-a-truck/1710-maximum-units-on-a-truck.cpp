class Solution {
    static bool comp(vector<int> &box1, vector<int> &box2) {
        return box1.back() > box2.back();
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int maxUnits = 0, k = 0;
        
        while(truckSize and k < n) {
            int boxes = boxTypes[k].front(), units = boxTypes[k].back();
            
            if(truckSize >= boxes) {
                maxUnits += boxes * units;
                truckSize -= boxes;
                }
            else {
                maxUnits += truckSize * units;
                truckSize = 0;
            }
            k++;
        }
        
        return maxUnits;
    }
};