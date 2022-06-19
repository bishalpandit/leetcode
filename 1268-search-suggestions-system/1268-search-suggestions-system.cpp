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
        vector<string> suggestions;
        
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
        
        void searchWords(Node* node, string build) {
            if(!node) return;
            if(node->flag) suggestions.push_back(build);
            
            for(int i = 0; i < 26; i++) {
                if(suggestions.size() == 3) return;
                if(node->links[i]) 
                    searchWords(node->links[i], build + (char)(97 + i));
            }
            
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
        
        vector<string> suggestWords(string keyword) {
            Node* node = root; string build;
            suggestions = vector<string>();
            
            if(!startsWith(keyword))
                return suggestions;
            
            for(auto &c: keyword) {
                build += c;
                node = node->next(c);
            }
            
            searchWords(node, build);
            
            return suggestions;
        }
    };
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size(), m = searchWord.size();
        vector<vector<string>> ans;
        
        Trie* t = new Trie();
        
        for(auto &product: products)
            t->insert(product);
        
        for(int i = 1; i <= m; i++) {
            string prefix = searchWord.substr(0, i);
            vector<string> suggestions = t->suggestWords(prefix);
            ans.push_back(suggestions);
        }
        
        return ans;
    }
};