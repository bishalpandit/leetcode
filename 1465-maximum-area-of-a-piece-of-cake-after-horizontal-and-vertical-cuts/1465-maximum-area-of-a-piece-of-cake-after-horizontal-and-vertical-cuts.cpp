class Solution {
    int MOD = 1000000007;
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        long long maxH = 0, maxV = 0, hn =  hc.size(), vn = vc.size();
        
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        maxH = max(hc[0], h - hc[hn - 1]);
        
        for(int i = 0; i < hn - 1; i++) {
            if((hc[i + 1] - hc[i]) > maxH)
            maxH = hc[i + 1] - hc[i];
        }
        
        maxV = max(vc[0], w - vc[vn - 1]);
        
        for(int i = 0; i < vn - 1; i++) {
            if((vc[i + 1] - vc[i]) > maxV) {
                maxV = vc[i + 1] - vc[i];
            }
        }
        
        long long ans = ((maxH%MOD) * (maxV%MOD))%MOD;
        
        return ans;
    }
};