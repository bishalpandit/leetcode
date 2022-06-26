class Solution {
public:
    int maxScore(vector<int>& pts, int k) {
        int n = pts.size();
        vector<int> pre(n, 0), suf(n, 0);
        int cur, ans = 0;
        
        for(int i = 0; i < n; ++i) {
            pre[i] = i == 0 ? pts[i] : pre[i - 1] + pts[i];
        }
        
        for(int i = n - 1; i >= 0; --i) {
            suf[i] = i == n - 1 ? pts[i] : suf[i + 1] + pts[i];
        }
        
        int l = -1, r = n - k;
        
        while(r <= n) {
            cur = ((l == -1) ? 0 : pre[l]) + ((r == n) ? 0 : suf[r]);
            ans = max(ans, cur);
            l++, r++;
        }
        
        return ans;
    }
};
/*

1 2 3 4 5 6 1

1 3 6 10 15 21 22

22 21 19 16 12 7 1
*/