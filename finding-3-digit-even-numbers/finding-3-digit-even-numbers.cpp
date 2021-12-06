class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        set<int> s;
        for(int i=0; i<n; i++) {
            if(digits[i] == 0)
                continue;
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    if(digits[k]%2 == 0 and i!=k and j!=k and i!=j) {
                        int num = (digits[i]*100 + digits[j]*10 + digits[k]);
                        s.insert(num);
                    }
                }
            }
        }
        
        copy(s.begin(), s.end(), back_inserter(ans));
        
        return ans;
    }
};

// 3-digits even number no-leading zeroes
/*
2130

002 012 210
001 000 012  102 
*/