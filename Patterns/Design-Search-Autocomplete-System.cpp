// https://www.codingninjas.com/studio/problems/design-search-autocomplete-system_3583446

#include <bits/stdc++.h>

// https://www.codingninjas.com/studio/problems/design-search-autocomplete-system_3583446?leftPanelTab=2&count=25&page=1&search=&sort_entity=order&sort_order=ASC
class AutocompleteSystem {
public:
  AutocompleteSystem(vector<string> &sentences, vector<int> &times) {
    for (int i = 0; i < sentences.size(); ++i)
      root_.Insert(sentences[i], times[i]);
    curr_node_ = &root_;
  }
  vector<string> input(char c) {
    if ('#' == c) {
      root_.Insert(prefix_, 1);
      prefix_ = "";
      curr_node_ = &root_;
      return {};
    }
    if (nullptr == curr_node_)
      return {};

    prefix_ += c;
    curr_node_ = curr_node_->children[Char2Index(c)];
    vector<string> result;
    if (nullptr != curr_node_) {
      for (const auto &hot_word : curr_node_->hot_words)
        result.push_back(hot_word->sentence);
    }
    return result;
  }
private:
    int Char2Index(char c) const { return ' ' == c ?  26 : c - 'a'; }

	struct TrieNode {
		TrieNode() {hot_words.reserve(4);}
		void Insert(const string& sentence, int hotness) {
			auto curr = this;
            vector<TrieNode*> visited;
			for(const auto& c : sentence) {
                auto child = Char2Index(c);
                if(nullptr == curr->children[child]) curr->children[child] = new TrieNode;
                curr = curr->children[child];
                visited.push_back(curr);
			}
            curr->hotness += hotness;
            if(true == curr->sentence.empty()) curr->sentence = sentence;
            for(const auto& trie_node : visited) trie_node->Update(curr);
		}
        void Update(TrieNode* that) {
            if(find(hot_words.begin(), hot_words.end(), that) == hot_words.end()) hot_words.push_back(that);
            sort(hot_words.begin(), hot_words.end(), [](const TrieNode* left, const TrieNode* right) 
            {return left->hotness == right->hotness ? left->sentence < right->sentence : left->hotness > right->hotness;});
            if(4 == hot_words.size()) hot_words.pop_back();
        }
        int Char2Index(char c) const { return ' ' == c ?  26 : c - 'a'; }
        int hotness{0};
        string sentence;
        vector<TrieNode*> hot_words;
		struct TrieNode* children[27] = {0};
	};
    
    TrieNode root_;
    TrieNode* curr_node_;
    string prefix_;
};


// https://aaronice.gitbook.io/lintcode/data_structure/design-search-autocomplete-system#leetcode-official
class AutocompleteSystem2 {
public:
  AutocompleteSystem2(vector<string> &sentences, vector<int> &times) {
    for (int i = 0; i < sentences.size(); ++i) root_.Insert(sentences[i], times[i]);
  }
  vector<string> input(char c) {
    if ('#' == c) {
      root_.Insert(prefix_, 1);
      prefix_ = "";
      return {};
    }

    prefix_ += c;
    vector<pair<int, string>> candidates = root_.Find(prefix_);
    sort(candidates.begin(), candidates.end(), 
    [](const pair<int, string>& p1, const pair<int, string>& p2) {return p1.first == p2.first ? p1.second < p2.second : p1.first > p2.first;});
    vector<string> result;
    for(int i = 0; i < min(3, (int) candidates.size()); ++i) result.push_back(candidates[i].second);
    return result;
  }
private:
    struct TrieNode {
        int Char2Index(char c) const { return ' ' == c ?  26 : c - 'a'; }
        void Insert(const string& sentence, int hotness) {
			auto curr = this;
			for(const auto& c : sentence) {
                auto child_index = Char2Index(c);
                if(nullptr == curr->children[child_index]) curr->children[child_index] = new TrieNode;
                curr = curr->children[child_index];
			}
            curr->hotness += hotness;
        }
        vector<pair<int, string>> Find(string prefix) {
            auto curr = this;
            for(const auto& c : prefix) {
                curr = curr->children[Char2Index(c)];
                if(nullptr == curr) return {};
            }
            vector<pair<int, string>> result;
            TraverseDeeper(curr, prefix, result);
            return result;
        }
        void TraverseDeeper(TrieNode* node, string& prefix, vector<pair<int, string>>& result) {
            if(nullptr == node) return;
            if(node->hotness) result.push_back({node->hotness, prefix});
            prefix.push_back('*');
            for(int c = 'a'; c <= 'z'; ++c) {
                prefix.back() = c;
                TraverseDeeper(node->children[Char2Index(c)], prefix, result);
            }
            prefix.back() = ' ';
            TraverseDeeper(node->children[Char2Index(' ')], prefix, result);
            prefix.pop_back();
        }
        int hotness{0};
		struct TrieNode* children[27] = {0};
    };
    TrieNode root_;
    string prefix_;
};