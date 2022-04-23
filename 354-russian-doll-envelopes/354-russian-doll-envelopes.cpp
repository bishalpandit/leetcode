class Solution {

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
     int size = envelopes.size();

	sort(envelopes.begin(), envelopes.end(), [&](vector<int> &a, vector<int> &b){
		return a.front() < b.front() || (a.front() == b.front() && a.back() > b.back());
	});
        
	vector<int> collector;
        
	for(auto& pair: envelopes)
	{
		auto iter = lower_bound(collector.begin(), collector.end(), pair.back());
		if(iter == collector.end()) collector.push_back(pair.back());
		else if(*iter > pair.back()) *iter = pair.back();
	}
        
	return collector.size();
        
    }
};