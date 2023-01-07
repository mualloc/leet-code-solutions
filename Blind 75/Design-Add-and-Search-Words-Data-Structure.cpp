class Trie{
    struct TrieNode;
   
public:
    Trie(){
        this->root = new TrieNode;
    }
    
    void insert(const string & word) {
        struct TrieNode* current = root;
        for(const char & c : word){
            if(nullptr == current->children[c - 'a']){
                current->children[c - 'a'] = new TrieNode;
            }
            current = current->children[c - 'a'];
        }
        current->isEndOfWord = true;
    }
    
    bool search(const string & word) {
        return search(word, root);
    }    
    
private:
    bool search(const string & word, struct TrieNode* current) {
        for(int i = 0; i < word.size(); ++i){
            const char & c = word[i];
            if('.' == c){
              for(int childIndex = 0; childIndex < TrieNode::kAlphabetSize; ++childIndex){
                  if(current->children[childIndex] && search(word.substr(i + 1), current->children[childIndex])) return true;
              } 
              return false;
            }
            else if(nullptr == current->children[c - 'a']) return false;
            else current = current->children[c - 'a'];
        }
        return current->isEndOfWord;
    }    
    
    struct TrieNode* root;
    
    struct TrieNode{
        TrieNode(){
            for(int i = 0; i < kAlphabetSize; i++) children[i] = nullptr;
            isEndOfWord = false;
        }
        
        enum AlphabetLimits {
            kAlphabetSize = 26
        };  
        
        struct TrieNode* children[kAlphabetSize];
        bool isEndOfWord;  
    }; 
};

class WordDictionary {
public:    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
    
private:
    Trie trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */