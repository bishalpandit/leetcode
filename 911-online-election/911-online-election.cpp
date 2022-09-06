class TopVotedCandidate {
    vector<int> persons, times, top_voted;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        
        int most_voted = 0;
        vector<int> votes(persons.size(), 0);
        
        for(int i = 0; i < persons.size(); i++) {
            votes[persons[i]]++;
            
            if(votes[persons[i]] >= votes[most_voted])
                most_voted = persons[i];
            
            top_voted.push_back(most_voted);
        }

    }
    
    int q(int t) {
        int topVotedIdx = upper_bound(times.begin(), times.end(), t) - times.begin();
        topVotedIdx--;
        return top_voted[topVotedIdx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */