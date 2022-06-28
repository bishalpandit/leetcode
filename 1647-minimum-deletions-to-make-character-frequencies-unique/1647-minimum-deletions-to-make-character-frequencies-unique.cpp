class Solution {

public:
    int minDeletions(string s) {
        map<char, int> m;
        
        for(auto &c: s)
            m[c]++;
        
        vector<int> freq;
        
        for(auto &[f, s]: m)
            freq.push_back(s);
        
        sort(begin(freq), end(freq), greater<int>());
        
        stack<int> st;
        int ans = 0;
        
        st.push(freq[0]);
        
        for(int i = 1; i < freq.size(); i++) {
            if(st.top() <= freq[i]) {
                ans += (st.top() == 0) ? freq[i] : (freq[i] - st.top()) + 1;
                st.push(max(st.top() - 1, 0));
            }
            else
                st.push(freq[i]);
        }
        
        return ans;
    }
};

/*

aaabbcce  

3 2 1 0 

aaaaa eeeee bbb ccc ddd ff k i j
0 3
1 + 1 + 2 + 2
*/