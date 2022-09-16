class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        
        sort(begin(changed), end(changed));
        multiset<int> ms;
        map<int, int> m; int zeroCount = 0;
        int k = 0;
                               
        for(auto &ele: changed) {
            if(ele == 0)
                zeroCount++;
            ms.insert(ele);
        }
                             
      if(zeroCount%2 != 0)
                return {};
        
      int halfZeroCount = zeroCount/2;
                                         
      for(int i = 0; i < n; i++) {
          if(changed[i] == 0) {
              if(halfZeroCount != 0) {
                ms.erase(ms.find(changed[i]));
                halfZeroCount--;
              }
              continue;
          }
          
          int doubled = 2 * changed[i];

          if(m[changed[i]]) {
             m[changed[i]]--;
              continue;
          }

          if(ms.count(doubled)) {
             ms.erase(ms.find(doubled));
             m[doubled]++;
          }
         else 
            return {};
  }
        
    vector<int> ans(ms.begin(), ms.end());
    return ans;
   }
};

/*

For every i, there should exist 2i.

i -> 2i

[2, 2, 4, 6, 11, 12, 13, 22, 26]
 *     *
 
 isMatched[] -> bool value if ele is already matched: Stores idx
2: [A[2] = 4]

if not matched:
 if 2*val in set
  remove one instance of 2*val from map i.e. remove idx and mark that idx as visited.  
 else
  return []
else
  skip
  
map -> 4: [1, 2]
 
[2, 4, 4]
    
*/