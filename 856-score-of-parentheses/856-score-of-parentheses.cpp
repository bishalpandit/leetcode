class Solution {
    pair<int,int> solve(int idx, string& s, int len) {
        if(s[idx] == '(' and s[idx+1] == ')') {
            return {1,idx+1};
        }
        
        int curScore = 0;
    
        int cur = idx + 1;
        
        for(; cur < len; cur++) {
            if(s[cur] == '(') {
                pair<int,int> p = solve(cur, s, len);
                curScore += p.first;
                cur = p.second;
            }
            
            else 
                break;
        }
        
    
        return {2*curScore,cur};
        
    }
public:
    int scoreOfParentheses(string s) {
        int len = s.length();
        int i = 0;
        int ans = 0;
        vector<pair<int,int>> streaks;
        
        for(int i=0; i<len; i++) {
            stack<char> st;
            int start = i;
            
            do {
                if(s[i] == '(')
                    st.push(s[i]);
                else
                    st.pop();
                i++;
            }while(!st.empty());
            
            i--;
            
            streaks.push_back({start, i});
        }
        
        
        
        for(auto p: streaks) {
            cout << p.first << " " << p.second << endl;
            ans += solve(p.first, s, p.second).first;
        }
        
        return ans;
    }
    
};