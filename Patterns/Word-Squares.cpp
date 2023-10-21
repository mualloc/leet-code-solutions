// https://www.codingninjas.com/studio/problems/word-squares_1235203

#include <bits/stdc++.h>

// https://walkccc.me/LeetCode/problems/0425/
struct TrieNode {
  void Insert(string &word) {
    auto curr = this;
    for (const auto &c : word) {
      auto child_index = ChildIndex(c);
      if (nullptr == curr->children[child_index]) curr->children[child_index] = new TrieNode;
      curr = curr->children[child_index];
      curr->words_starting_with.push_back(word);
    }
  }

  vector<reference_wrapper<string>> FindByPrefix(const string &prefix) const {
    auto curr = this;
    for (const auto &c : prefix) {
      if (nullptr == (curr = curr->children[ChildIndex(c)])) return {};
    }
    return curr->words_starting_with;
  }

private:
  int ChildIndex(char c) const { return c - 'a'; }
  TrieNode *Child(char c) const { return children[ChildIndex(c)]; }
  struct TrieNode *children[26] = {0};
  vector<reference_wrapper<string>> words_starting_with;
};

string GetPrefix(vector<string> &path) {
  string result;
  int index = path.size();
  for (const auto &row : path) result += row[index];
  return result;
}

void wordSquaresHelper(int target_size, const TrieNode &trie, vector<string> &current_square, vector<vector<string>> &result) {
  if (current_square.size() == target_size) {
    result.push_back(current_square);
    return;
  }
  string prefix = GetPrefix(current_square);
  vector<reference_wrapper<string>> candidate_words = trie.FindByPrefix(prefix);
  for (const auto &candidate : candidate_words) {
    current_square.push_back(candidate);
    wordSquaresHelper(target_size, trie, current_square, result);
    current_square.pop_back();
  }
}

// TC: O(N^L * L)
vector<vector<string>> wordSquares(vector<string> &arr) {
  TrieNode trie;
  for (auto &word : arr) trie.Insert(word);
  vector<vector<string>> result;
  vector<string> current_square;
  for (const auto &word : arr) {
    current_square.push_back(word);
    wordSquaresHelper(word.size(), trie, current_square, result);
    current_square.pop_back();
  }
  return result;
}

/*struct TrieNode {
        void Insert(const string& word) {
                auto curr = this;
                for(const auto& c : word) {
            auto child_index = ChildIndex(c);
            if(nullptr == curr->children[child_index])
curr->children[child_index] = new TrieNode; curr = curr->children[child_index];
                }
        }
  int ChildIndex(char c) const { return c - 'a'; }
  TrieNode* Child(char c) { return children[ChildIndex(c)]; }
        struct TrieNode* children[26] = {0};
};

void wordSquaresHelper(const vector<string> &words, vector<TrieNode*>& nodes,
vector<string>& current_square, vector<vector<string>>& result) {
    if(current_square.size() == words[0].size()) {
        result.push_back(current_square);
        return;
    }

    for(const auto& word : words) {
        vector<TrieNode*> new_nodes;
        for(int node_index = 0; node_index < nodes.size(); ++node_index) {
            if(auto child_node = nodes[node_index]->Child(word[node_index]))
new_nodes.push_back(child_node); else break;
        }
        if(word.size() == new_nodes.size()) {
            current_square.push_back(word);
            wordSquaresHelper(words, new_nodes, current_square, result);
            current_square.pop_back();
        }
    }
}

vector<vector<string>> wordSquares(vector<string> &arr) {
    TrieNode trie;
    for(const auto& word : arr) trie.Insert(word);
    vector<vector<string>> result;
    vector<string> current_square;
    vector<TrieNode*> nodes(arr[0].size(), &trie);
    wordSquaresHelper(arr, nodes, current_square, result);
    return result;
}*/
