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
        
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        
        for(auto &c: word) {
            if(!node->containsKey(c))
                return false;
            node = node->next(c);
        }
        
        return node->flag;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */