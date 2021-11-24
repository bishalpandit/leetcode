class Solution {
    bool canEatAllBananas(int k, vector<int>& piles, int h) {
        int cntHrs = 0, n = piles.size();

        for(int i=0; i<n; i++) {
            cntHrs += ceil(((double)piles[i]/k));
            if(cntHrs > h) 
                return false;
        }
        
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1,
        hi = *max_element(piles.begin(), piles.end());
        
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            if(canEatAllBananas(mid, piles, h))
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return lo;
        
    }
};

/*
logMax(piles)*n
*/