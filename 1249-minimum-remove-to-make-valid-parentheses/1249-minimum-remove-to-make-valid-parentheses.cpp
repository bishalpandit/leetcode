class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        
        int len = s.length();
        string ans;
        
        for(int i=0; i<len; i++) {
            if(s[i] == ')' and !st.empty() and st.top().first == '(') 
                st.pop();
            
            else if(s[i] == ')')
                st.push({s[i], i});
            
            if(s[i] == '(')
                st.push({s[i],i});
        }
            
        set<int> removeIndexesSet;
            
        while(!st.empty()) {
            removeIndexesSet.insert(st.top().second); st.pop();
            }
            
       for(int i=0; i<len; i++) {
           if(!removeIndexesSet.count(i))
               ans += s[i];
       }
            
        return ans;
    }
};

// (((a(b)c( ((((