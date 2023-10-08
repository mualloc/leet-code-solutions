class WordFilter {
public:
    // TC: O(C * L^2)
    // SC: O(C * L^2 * 27)
    WordFilter(vector<string>& words) {
        const auto words_size = words.size();
        for(int index = 0; index < words_size; ++index) {
            const auto& word = words[index];
            const auto word_size = word.size();
            for(int i = 0; i < word_size; ++i)  trie_root.insert(word.substr(i) + seperator + word, index);      
        }
    }

    // TC: O(L)
    int f(string pref, string suff) {
        return trie_root.findIndex(suff + seperator + pref);
    }
private:
    struct TrieNode{
        void insert(const string& word, int index){
            auto curr = this;
            for(const auto& character : word) {
                auto child_index = character - 'a';
                if(0 == curr->children[child_index]) curr->children[child_index] = new TrieNode;
                curr = curr->children[child_index];
                curr->index = index;
            }
        }
        int findIndex(const string& word){
            auto curr = this;
            for(const auto& character : word) {
                curr = curr->children[character - 'a'];
                if(0 == curr) return -1;
            }
            return curr->index;
        }
        struct TrieNode* children[27] = {0};
        int index = -1;
    };
    TrieNode trie_root;
    const char seperator {'z' + 1};
};


class WordFilter2 {
public:
    // TC: O(C * L^2)
    // SC: O(C * L^2)
    WordFilter2(vector<string>& words) {
        const auto words_size = words.size();
        for(int index = 0; index < words_size; ++index) {
            const auto& word = words[index];
            const auto word_size = word.size();
            for(int i = 0; i < word_size; ++i) {
                prefix_dictionary[word.substr(0, i + 1)].push_back(index);
                suffix_dictionary[word.substr(i)].push_back(index);
            }
        }
    }
    
    // TC: O(C * logC)
    int f(string pref, string suff) {
        const auto& pref_indexes = prefix_dictionary[pref];
        const auto& suff_indexes = suffix_dictionary[suff];
        auto get_largest_common_index = [](const auto& search_for, const auto& search_in) {
            for(int i = search_for.size() - 1; i > -1; --i) {
                if (binary_search(search_in.begin(), search_in.end(), search_for[i])) return search_for[i];
            }     
            return -1;
        };
        return suff_indexes.size() > pref_indexes.size() ? get_largest_common_index(pref_indexes, suff_indexes) : get_largest_common_index(suff_indexes, pref_indexes);
    }
private:
    unordered_map<string, vector<int>> prefix_dictionary;   // ("prefix", index)
    unordered_map<string, vector<int>> suffix_dictionary;   // ("suffix", index)
};



class WordFilter3 {
public:
    // TC: O(C * L^3)
    // SC: O(C * L^3)
    WordFilter3(vector<string>& words) {
        const auto words_size = words.size();
        for(int index = 0; index < words_size; ++index){
            const auto& word = words[index];
            const auto word_size = word.size();
            for(int i = 0; i < word_size; ++i){
                const auto prefix = word.substr(0, i + 1);
                for(int j = 0; j < word_size; ++j){
                    const auto suffix = word.substr(j);
                    dictionary[prefix + "/" + suffix] = index;  // Overwrites with larger index if already exists
                }
            }
        }
    }
    
    // TC: O(L)
    int f(string pref, string suff) {
        if(auto it = dictionary.find(pref + "/" + suff); dictionary.end() != it) return it->second;
        else return -1;
    }
private:
    unordered_map<string, int> dictionary;   // ("prefix/suffix", index)
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
