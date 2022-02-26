class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket: tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        
        visit("JFK");
        return vector<string>(routes.rbegin(), routes.rend());
    }
    
    map<string, multiset<string>> graph;
    vector<string> routes;
    
    void visit(string airport) {
        
        while(!graph[airport].empty()) {
            string next_airport = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            visit(next_airport);
        }
        
        routes.push_back(airport);
        
    }
};

/*

*/