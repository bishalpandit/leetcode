class Solution {

public:
    int scoreOfParentheses(string s) {
        int len = s.length();
        stack<int> st;
        st.push(0); // Push 0 for the answer score.
        
        for(int i = 0; i < len; ++i) {
            if(s[i] == '(') 
                st.push(0);
            else {
                int cur = st.top(); st.pop();
                int prev = st.top(); st.pop();
                
                st.push(prev + max(2*cur, 1));
            }
        }
        
        return st.top();
    }
};
// if ( -> 0, ) -> 1 if it's just (), 2*0 then take 1. But if ((())), then mult by 2.here max(2*0,1) 1 -> max(2*1,1) 2 -> max(2*2,1)
    