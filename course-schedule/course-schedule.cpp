class Solution {
    bool topoSort(vector<vector<int>>& adj, int n) {
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
        

        return topo.size() == n;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses, e = prerequisites.size();
        if(e == 0)
            return true;
        vector<vector<int>> adj(n);
        
        for(int i=0; i<e; i++) {
            int u, v;
            u = prerequisites[i].back(); v = prerequisites[i].front();
            adj[u].push_back(v);
        }
        
        for(auto list: adj)
            for(auto val: list)
                cout << val << " ";
        return topoSort(adj, n);
    }
};

/*

b->a
adj[b].pb(a);
1,0 2,0
*/