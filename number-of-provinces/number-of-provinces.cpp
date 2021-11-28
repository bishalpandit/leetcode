class Solution {
    class UnionFind {
        vector<int> parent;
        vector<int> rank;
        public:
        UnionFind(int n) : parent(n+1), rank(n+1) {}
        
        void makeSet(int n) {
            for(int i=1; i<=n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }
        
        int findParent(int node) {
            if(parent[node] == node)
                return node;
            return parent[node] = findParent(parent[node]);
        }
        
        void unify(int u, int v) {
            u = findParent(u);
            v = findParent(v);
            if(u == v)
                return;
            
            if(rank[u] == rank[v]) {
                parent[u] = v;
                rank[v]++;
            }
            else if(rank[u] > rank[v]) {
                parent[v] = u;
            }
            else {
                parent[u] = v;
            }
        }
    };
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind *UF = new UnionFind(n);
        UF->makeSet(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] and i!=j)
                    UF->unify(i+1, j+1);
            }
        }
        
        vector<int> ans(n+1,0);
        
        for(int i=1; i<=n; i++) {
            int par = UF->findParent(i);
            ans[par] = 1;
        }
        
        int res = accumulate(ans.begin(), ans.end(), 0);
        
        return res;
    }
};

// connected -> 
// 1 1 0
// 1 1 0
// 0 0 1