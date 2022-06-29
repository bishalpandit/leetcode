class Solution {
     map<vector<string>, double> answers;
    
    void dfs(string node, map<string, bool> &vis, map<string, vector<pair<string, double>>> &adj, double mult, vector<string> temp) {
        vis[node] = true;
        
        if(!temp.size()) {
            temp.push_back(node);
        }
        
        else {
            answers.insert({{temp[0], node}, mult});
        }
        
        for(auto &v: adj[node]) {
            if(!vis[v.first]) {
                dfs(v.first, vis, adj, mult * v.second, temp);
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        
        for(int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
    
        set<string> nodes;
        
        for(auto &e: equations) {
            nodes.insert(e[0]);
            nodes.insert(e[1]);
        }
        
        map<string, bool> vis;
        double mult = 1.00;
        vector<string> temp;
        
    
        for(auto &node: nodes) {
            answers.insert({{node, node}, 1.0});
            dfs(node, vis, adj, mult, temp);
            vis.clear();
        }
        
        vector<double> res;
        
        for(auto &q: queries) {
            if(answers[q])
                res.push_back(answers[q]);
            else
                res.push_back(-1.0);
        }
        
        return res;
    }
};