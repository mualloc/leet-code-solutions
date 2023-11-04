// https://www.codingninjas.com/studio/problems/ninja-and-index-pairs_1462451
// https://leetcode.ca/all/1065.html

#include <unordered_set>

class TrieNode {
public:
	void insert(const string& word) {
		TrieNode *curr = this;
		for(const auto& c : word) {
			const auto i = c - 'a';
			if(nullptr == curr->children[i]) curr->children[i] = new TrieNode;
			curr = curr->children[i];
		}
                curr->is_word = true;
	}
        TrieNode *getChild(int c) {return children[c - 'a'];}
        bool isWord() {return is_word;}
private:
	TrieNode *children[26] = {};
        bool is_word{false};
};

// TC: O(N * WL + T^2)
vector<vector<int>> indexPairs(string &text, vector<string> &words) {
        TrieNode trie;
        for(const auto& word : words) trie.insert(word);

        vector<vector<int>> result;
        for(int i{0}, text_size = text.size(); i < text_size; ++i) {
                TrieNode *curr{&trie};
                for(int j{i}; j < text_size; ++j) {
                        if(curr = curr->getChild(text[j])){
                                if(curr->isWord()) result.push_back({i, j});
                        }else break;
                }
        }
        return result;
}


// TC: O(N * WL * T + T^2 * logT)
vector<vector<int>> indexPairs2(string &text, vector<string> &words) {
        vector<vector<int>> result;
        for(const auto& word : words) {
                const auto text_size{text.size()};
                const auto word_size{word.size()};
                for(int i{0}; i < text_size - word_size + 1; ++i) {
                        if(word == text.substr(i, word_size)) result.push_back({i, i + word_size - 1});
                }
        }
        sort(result.begin(), result.end());     // <-- + T^2 * logT TC complexity is in here!
        return result;
}


// TC: O(N * WL + WL * T^2)
vector<vector<int>> indexPairs3(string &text, vector<string> &words) {
        unordered_set<string> dictionary(make_move_iterator(words.begin()),
              make_move_iterator(words.end()));

        vector<vector<int>> result;
        for(int i{0}, text_size = text.size(); i < text_size; ++i) 
            for(int j{i}; j < text_size; ++j) 
                if(dictionary.end() != dictionary.find(text.substr(i, j - i + 1))) result.push_back({i, j});
                
        return result;
}
