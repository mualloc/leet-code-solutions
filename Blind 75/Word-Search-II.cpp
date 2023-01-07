class Trie{
public:
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
    
    Trie(){
        this->root_ = new TrieNode;
    }
    
    void insert(const string & word) {
        struct TrieNode* current = root_;
        for(const char & c : word){
            if(nullptr == current->children[c - 'a']){
                current->children[c - 'a'] = new TrieNode;
            }
            current = current->children[c - 'a'];
        }
        current->isEndOfWord = true;
    }
    
    struct TrieNode* root(){
        return this->root_;
    }
    
private:
    struct TrieNode* root_;
};


class Solution {
public:
    // TC: O(M * N * 4 * 3^(L-2) + S) where L <= 10 is the maximum length of words, S <= 3 * 10^5 is sum length of all words.
    // Explain: Firstly, we can choose M*N cells of the board as starting position, we have 4 choices to go neighbors of the first cell, each of neighbors have total 3 choices to go to their neighbors (exclude their previous neighbor) and so on.
    // Space: O(S)
    // Explain: The main space consumed by the algorithm is the Trie data structure we build. In the worst case where there is no overlapping of prefixes among the words, the Trie would have as many nodes as the letters of all words.
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = CreateTrie(words);
            
        vector<string> result;  
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                string prefix = "";
                findWord(board, i, j, prefix, trie->root(), result);
            }
        }
        
        delete trie;
        return result;
    }
    
private:
    void findWord(vector<vector<char>>& board, int row, int col, string & prefix, struct Trie::TrieNode* trieNode, vector<string> & result){        
        const int nRows = board.size();
        const int nCols = board[0].size();
        if(row < 0 || row == nRows || col < 0 || col == nCols || 0 == board[row][col]  
                   || nullptr == trieNode->children[board[row][col] - 'a']) return;
        
        prefix += board[row][col];
        trieNode = trieNode->children[board[row][col] - 'a'];
        if(trieNode->isEndOfWord){
            result.push_back(prefix); 
            trieNode->isEndOfWord = false;
        }
               
        board[row][col] = 0;
        findWord(board, row + 1, col, prefix, trieNode, result);
        findWord(board, row - 1, col, prefix, trieNode, result);
        findWord(board, row, col + 1, prefix, trieNode, result);
        findWord(board, row, col - 1, prefix, trieNode, result);
        board[row][col] = prefix.back();
        prefix.pop_back();
    }
    
    Trie* CreateTrie(const vector<string>& words){
        Trie* trie = new Trie;
        for(const auto & word : words) trie->insert(word);
        return trie;
    }
};