class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.size();
        int cnt = 0, i = 0;
        
        if(n >= 2 and (street.substr(0,2) == "HH" or street.substr(n-2,2) == "HH"))
           return -1;
            
        
        while(i < n) {
            
            if(street[i] == 'H') {
                
                if(i < n-2 and street[i+1] == '.' and street[i+2] == 'H') {
                    cnt++;
                    i += 3;
                    continue;
                }
                else if(i < n-1 and street[i+1] == '.')
                    cnt++;
                else if(i > 0 and street[i-1] == '.')
                    cnt++;
                else return -1;
                
                i++;
            }
            
            else
                i++;
        }
        
        return cnt;
    }
};

/*
H.H
H..
.HH
HHH
*/