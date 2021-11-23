class Solution {
        vector<int> parent;
        
        
        int findParent(int node) {
            if(parent[node] == node)
                return node;
            return parent[node] = findParent(parent[node]);
        }
        
        void Union(int u, int v) {
            u = findParent(u);
            v = findParent(v);
            
            parent[v] = u;
        }
        
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        mx = *max_element(nums.begin(), nums.end());
        parent.resize(mx+1);
        for(int i=1; i<=mx; i++)
            parent[i] = i;
        
        for(auto &x: nums) {
            for(int i=2; i*i<=x; i++)
                if(x%i == 0) {
                    Union(x, i);
                    Union(x, x/i);
                }
        }
        
        vector<int> cntParent(mx+1, 0);
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            int parent = findParent(nums[i]);
            cntParent[parent]++;
            ans = max(ans, cntParent[parent]);
        }
        
        return ans;
    }
};

