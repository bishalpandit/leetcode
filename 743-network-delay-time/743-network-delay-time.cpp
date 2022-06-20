class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX), vis(n + 1, 0);
        priority_queue<pair<int, int>> pq;
        vector<pair<int, int>> adj[n + 1];
        
        for(auto &e: times) 
            adj[e[0]].push_back({e[1], e[2]});
        
        dist[k] = 0;
        pq.push({0, k});
        
        while(pq.size()) {
            auto u = pq.top(); pq.pop();
            vis[u.second] = 1;
            
            for(auto &v: adj[u.second]) {
                if(!vis[v.first] and dist[v.first] > (dist[u.second] + v.second)) {
                    dist[v.first] = dist[u.second] + v.second;
                    pq.push({-dist[v.first], v.first});
                }
            }    
        }
        
        
        for(int i = 1; i <= n; i++)
            if(!vis[i]) return -1;
        
        int ans = *max_element(dist.begin() + 1, dist.end());
        
        return ans;
    }
};