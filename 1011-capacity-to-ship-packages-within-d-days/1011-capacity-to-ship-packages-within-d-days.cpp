class Solution {
    bool canShip(int mid, vector<int> &weights, int days) {
        int k = 1, curSum = 0;
        
        for(int i = 0; i < weights.size(); i++) {
            if(curSum + weights[i] <= mid) 
                curSum += weights[i];
            else {
                curSum = weights[i];
                k++;
            }
            
            if(k > days)
                return false;
        }
        
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        
        int mid;
        
        while(lo < hi) {
            mid = (lo + hi)/2;
            
            if(canShip(mid, weights, days))
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return lo;
    }
};
/*
lo = minOfAll and hi = sumOfAll

1 2 3 3  days = 3

1 9

3

1 2 3 3

for i in n
    if(curSum + val <= mid) 
        curSum += val;
    else {
        curSum = val;
        
        days++;
    }
    if(days > k)
        return false;


1 5
3
*/
