class Solution {
    class UnionFind {
        vector<int> parent;
        vector<int> rank;
        public:
        
        UnionFind(int n) : parent(n), rank(n) {}
        
        void makeSet(int n) {
            for(int i=0; i<n; i++) {
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
            if(u == v) // if same parent no need to do anything
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
          int n = accounts.size();
        
          UnionFind *UF = new UnionFind(n);
          UF->makeSet(n);
        
        vector<unordered_set<string>> accountsMap(n);
        
        for(int i=0; i<n; i++) {
            for(int j = 0; j<accounts[i].size(); j++) {
                accountsMap[i].insert(accounts[i][j]);
            }
            
        }
        
        for(auto s: accountsMap)
            for(auto val: s)
                cout << val << " ";
        
        for(int i=0; i<n; i++) {
            
            string name = accounts[i][0];
            
            for(int j=i+1; j<n; j++) {
                
                if(accountsMap[j].count(name)) {
                     
                    for(int k=1; k<accounts[i].size(); k++) {
                        string email = accounts[i][k];
                        
                        if(accountsMap[j].count(email)) {
                            
                            UF->unify(i,j);
                        }
                    }
                }
            }
        }
        
        map<int, set<string>> ansMap;
        
        for(int i=0; i<n; i++) {
            int par = UF->findParent(i);
            for(int j=1; j<accounts[i].size(); j++) {
                ansMap[par].insert(accounts[i][j]);
                
            } 
        }
        vector<vector<string>> ans;
        
        for(auto [f, s]: ansMap) {
            vector<string> temp;
            temp.push_back(accounts[f][0]);
            copy(s.begin(), s.end(), back_inserter(temp));
            ans.push_back(temp);
        }
        
        return ans;
    }
};

// 1 : 0, 1
