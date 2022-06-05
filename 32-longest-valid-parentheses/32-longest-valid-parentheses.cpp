class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int mx = 0, n = s.size();

        st.push(-1); // Initial starting point for () streak
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(')
                st.push(i);
            else {
                st.pop();
                if(st.empty()) {
                    st.push(i); // Making it the new starting point for next () streak
                }
                else {
                    mx = max(mx, i - st.top());
                }
            }
        }
        
        return mx;
    }
};

