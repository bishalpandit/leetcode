class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size(), score = 0, ans = 0;
        int i = 0, j = n - 1;
        
        sort(tokens.begin(), tokens.end());
        
        while(i <= j) {
            if(power >= tokens[i]) {
                score++;
                power -= tokens[i];
                i++;
                ans = max(ans, score);
            }
            else if(score >= 1) {
                score--;
                power += tokens[j];
                j--;
            }
            else
                break;
        }
        
        return ans;
    }
};