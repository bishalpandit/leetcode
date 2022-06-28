class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> m;
        
        for(auto &w: words)
            m[w]++;
        
        int count = 0;
        bool flag = false;
        
        for(auto &w: words) {
            string r = w;
            reverse(r.begin(), r.end());
            
            if(w != r and m[w] > 0 and m[r] > 0) {
                count += 4;
                m[w]--;
                m[r]--;
            }
            else if(w == r and m[w] > 1) {
                count += 4;
                m[w] -= 2;
            }
            else if(w == r and !flag and m[w] == 1) {
                count += 2;
                m[w]--;
                flag = !flag;
            }
        }
        
        return count;
    }
};


/*
fa af fc cf
- put reversed two char words in multiset
- check if w[i] there, also remove its reverse(ab -> remove ab, remove ba)
- w[0] == w[1], count this type of word once only.
aabbbbaa aa
 aa
 bb cc 
*/