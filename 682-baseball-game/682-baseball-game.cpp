class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        
        stack<int> s;
        
        for(int i=0; i<n; i++) {
            
            if(ops[i] == "D" or ops[i] == "C" or ops[i] == "+") {
                char ch = ops[i][0];
                int p1, p2;
                switch(ch) {
                    case 'D': 
                        p1 = s.top();
                        s.push(2*p1);
                        break;
                    case 'C': 
                        s.pop();
                        break;
                    case '+': 
                        p1 = s.top(); s.pop();
                        p2 = s.top();
                        s.push(p1);
                        s.push(p1+p2);
                        break;
                }
                
            } else {
                int num = stoi(ops[i]);
                s.push(num);
            }
        }
        
        int ans = 0;
        while(!s.empty()) {
            ans += s.top(); s.pop();
        }
        
        return ans;
    }
};