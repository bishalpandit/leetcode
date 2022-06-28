class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> freq;
        int curTime = 0;
              
        for(auto &t: tasks)
            freq[t]++;
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        
        for(auto &[f, s]: freq)
            pq.push({0, f});
        
        while(!freq.empty()) {
            auto task = pq.top();
            
            if(task.first <= curTime) {
                pq.pop();
                if(freq[task.second] > 1) {
                    freq[task.second]--;
                    pq.push({task.first + n + 1, task.second});
                }
                else 
                    freq.erase(task.second);
            }
            
            curTime++;
        }
        
        return curTime;
    }
};