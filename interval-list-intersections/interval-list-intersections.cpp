class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size(), n = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> res;
        while(i < m and j < n) {
            
            int si = firstList[i].front(), ei = firstList[i].back();
            int sj = secondList[j].front(), ej = secondList[j].back();
            
            int start = max(si, sj); // start of intersection interval
            int end = min(ei, ej);  // end of intersection interval
            
            if(start <= end) // if there exists an intersection interval, st <= end
                res.push_back({start, end});
            
            if(ei <= ej)
                i++;
            else
                j++;
        }
        
        return res;
    }
};