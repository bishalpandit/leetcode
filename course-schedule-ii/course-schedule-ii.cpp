class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          int n = numCourses, e = prerequisites.size();

        vector<vector<int>> adj(n);
        
        for(int i=0; i<e; i++) {
            int u, v;
            u = prerequisites[i].back(); v = prerequisites[i].front();
            adj[u].push_back(v);
        }
        
         vector<int> indeg(n,0);
        
        for(int i=0; i<n; i++) 
            for(auto v: adj[i])
                indeg[v]++;
        
        
        queue<int> q;
        
        for(int i=0; i<n; i++) {
            if(indeg[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            for(auto v: adj[node]) {
                indeg[v]--;
                if(indeg[v] == 0)
                    q.push(v);
            }
        }
        

        if(topo.size() == n)
            return topo;
        else
            return {};
    }
};