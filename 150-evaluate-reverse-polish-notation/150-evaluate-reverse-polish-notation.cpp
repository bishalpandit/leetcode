class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        
        stack<string> st;
        
        for(int i = 0; i < n; i++) {
            if(tokens[i]  == "+" or tokens[i] == "*" or tokens[i] == "-" or tokens[i] == "/") {
                int op2 = stoi(st.top()); st.pop();
                int op1 = stoi(st.top()); st.pop();
                
                int res;
                
                switch(tokens[i][0]) {
                    case '+': res = op1 + op2; break;
                    case '-': res = op1 - op2; break;
                    case '*': res = op1 * op2; break;
                    case '/': res = op1 / op2; break;
                }
                
                st.push(to_string(res));
            }
            else
                st.push(tokens[i]);
        }
        
        int ans = stoi(st.top());
        
        return ans;
    }
};