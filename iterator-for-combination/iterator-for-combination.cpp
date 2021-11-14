class CombinationIterator {
    string str;
    int len, cur, noOfValidCombs;
    vector<string> validCombs;
    vector<string> allCombs;
    
    void findAllCombs(string str) {
        int len = str.length();
        int validLen = this->len;
        allCombs.push_back("");
        
        for(int i=0; i<len; i++) {
            
            int k = allCombs.size();
            char ch = str[i];
            
            for(int i=0; i<k; i++) {
                
                string subset;
                subset = allCombs[i] + ch;
                allCombs.push_back(subset);
            }
        }
        
        for(auto &str: allCombs) {
            if(str.size() == validLen)
                validCombs.push_back(str);
        }
            
        sort(validCombs.begin(),validCombs.end());
    }
    
    
public:
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        len = combinationLength;
        findAllCombs(str);
        cur = 0;
        noOfValidCombs = validCombs.size();
    }
    
    string next() {
        if(cur == noOfValidCombs)
            return "";
        
        return validCombs[cur++];
    }
    
    bool hasNext() {
        return cur != noOfValidCombs;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


// abc acb bac bca cab cba ab ac bc