class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int slen = s.length(), tlen = t.length();
        string ans1, ans2;
        
        int i = 0;
        
         while(i<slen) {
            int bksp_cnt = 0;
             
            while(i<slen and s[i] != '#') ans1+= s[i], i++;
            
            while(i<slen and s[i] == '#') bksp_cnt++, i++;
            
            while(bksp_cnt-- and !ans1.empty())
                ans1.pop_back();
        }
        
        i = 0;
        
        while(i<tlen) {
            int bksp_cnt = 0;
            while(i<tlen and t[i] != '#') ans2+= t[i], i++;
            
            while(i<tlen and t[i] == '#') bksp_cnt++, i++;
            
            while(bksp_cnt-- and !ans2.empty())
                ans2.pop_back();
        }
        
      //  cout << newT << " " << newS;
        return ans1 == ans2;
        
    }
};

/*btw

bxj##tw
bxo#j##tw

*/