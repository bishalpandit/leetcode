class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        
        sort(people.begin(), people.end(), greater<int>());
        
        int i = 0, j = n - 1, ans = 0;
        
        while(i <= j) {
            if(people[i] + people[j] <= limit)
                j--, ans++;
            else
                ans++;
            i++;
        }
        
        return ans;
    }
};

//  5 4 3 3