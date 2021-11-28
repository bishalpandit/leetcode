class Solution {
    void dfs(int node, vector<vector<int>>& graph, int target, vector<int>& path, vector<vector<int>>& paths) {
        if(node == target) {
            path.push_back(node);
            paths.push_back(path);
            path.pop_back();
            return;
        }
        
        for(auto adj: graph[node]) {
            path.push_back(node);
            dfs(adj, graph, target, path, paths);
            path.pop_back();
            }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        vector<int> path;
        dfs(0, graph, n-1, path, paths);
        return paths;
    }
};