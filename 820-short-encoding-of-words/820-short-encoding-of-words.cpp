class Solution {
    
    struct Node {
    Node* links[26];
    bool flag;
    bool containsKey(char c) {
        return links[c - 'a'] != NULL;
    }
    void insertKey(char c, Node* node) {
        links[c - 'a'] = node;
    }
    Node* next(char c) {
        return links[c - 'a'];
    }
};

class Trie {
    Node* root;
    public: 

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for(auto &c: word) {
            if(!node->containsKey(c))
                node->insertKey(c, new Node());
            node = node->next(c);
        }

        node->flag = true; // A strings ends here.
    }
    
    bool startsWith(string prefix) {
        Node* node = root;

        for(auto &c: prefix) {
            if(!node->containsKey(c))
                return false;
            node = node->next(c);
        }
        return true;
    }
};
public:
    int minimumLengthEncoding(vector<string>& words) {

        Trie *t = new Trie();
        int ans = 0;
        
        for(auto &w: words)
            reverse(w.begin(), w.end());
        
        sort(words.begin(), words.end());
        reverse(words.begin(), words.end());
        
        for(auto &w: words) 
            if(!t->startsWith(w)) {
                t->insert(w);
                ans += w.size() + 1;
            }
        
        return ans;
    }
};

/*

*/