/*struct TrieNode{
    TrieNode(){
        this->isWord = false;
        memset(children, 0, sizeof(children));
    }
    bool isWord;
    TrieNode *children[26];
};*/


class Trie {
public:
    /*Trie() {
        this->root = new TrieNode;
    }*/
    
    void insert(string word) {
        Trie/*Node*/ *current = /*root*/this;
        for(auto character : word){
            if(nullptr == current->children[character - 'a']){
                current->children[character - 'a'] = new Trie/*Node*/;
            }
            current = current->children[character - 'a'];
        }
        current->isWord = true;
    }
    
    bool search(string word) {
        Trie/*Node*/ *current = /*root*/this;
        for(auto character : word){
            if(nullptr == current->children[character - 'a']) return false;
            else current = current->children[character - 'a'];
        }
        return current->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie/*Node*/ *current = /*root*/this;
        for(auto character : prefix){
            if(nullptr == current->children[character - 'a']) return false;
            else current = current->children[character - 'a'];
        }
        return true;
    }
private:
    bool isWord = false;
    Trie *children[26] = {0};
    //TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */