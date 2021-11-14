class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> freq;
        
        for(auto const &ch: s)
            ++freq[ch];
        
        set<char> chars;
        int cnt = 0;
        vector<int> res;
        
        for(auto &ch: s) {
            
            if(chars.find(ch) == chars.end()) // if its 1st occurence of any char, put it in set
                chars.insert(ch);
            cnt++;
            
             // if freq is non-zero, decrement by 1
            freq[ch]--;
            
            
            if(!freq[ch])
                chars.erase(ch);
            
            
            if(chars.empty()) {
                res.push_back(cnt);
                cnt = 0;
            }
        }
        
        
        return res;
    }
};

// eccbbbbdec
// e: 1, c: 1, b: 0, d: 1
//set for keeping track of a segment or partition.
// when set becomes empty, you get a partition
// maintain a map for freq of chars