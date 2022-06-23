class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1)
            return strs[0];
        
        string ans;
        int len = 200;
        
        for(int i = 0; i < n - 1; i++) {
            string s1 = strs[i], s2 = strs[i + 1];
            string temp;
            
            for(int j = 0; j < s1.size() and j < s2.size(); j++) {
                if(s1[j] != s2[j])
                    break;
                temp += s1[j];
            }
            
            if(temp.size() < len) {
                len = temp.size();
                ans = temp;
            }
        }

        return ans;
    }
};