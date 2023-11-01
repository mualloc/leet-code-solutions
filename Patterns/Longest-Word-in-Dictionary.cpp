class Solution {
public:
    // TC: O(W*L)
    string longestWord(vector<string>& words) {
        TrieNode trie(0);
        for(auto& word : words) trie.insert(word);

        string *result{nullptr};
        queue<TrieNode*> queue{{&trie}};
        while(!queue.empty()) {
            result = queue.front()->getWord();
            for(int q_size = queue.size(); q_size > 0; --q_size) {
                auto top{queue.front()}; queue.pop();
                for(const auto& node : top->childWordNodes()) queue.push(node);
            }
        }
        return result ? *result : "";
    }
private:
    class TrieNode {
    public:
        TrieNode(string *word = nullptr) : word{word} {}
        void insert(const string& word) {
            TrieNode *curr = this;
            for(const auto& c : word) {
                const auto i = c - 'a';
                if(nullptr == curr->children[i]) curr->children[i] = new TrieNode;
                curr = curr->children[i];
            }
            curr->word = const_cast<string*>(&word);
        }
        vector<TrieNode*> childWordNodes() {
            vector<TrieNode*> nodes;
            for(const auto& child : children) if(child && child->word) nodes.push_back(child);
            return nodes;
        }
        string * getWord() {return word;}
    private:
        TrieNode *children[26] = {0};
        string *word{nullptr};
    };
};


class Solution2 {
public:
    // TC: O(W*L*26)
    string longestWord(vector<string>& words) {
        unordered_set<string> dictionary(make_move_iterator(words.begin()),make_move_iterator(words.end()));
        string result;

        queue<string> queue{{""}};
        while(!queue.empty()) {
            result = queue.front();
            for(int q_size = queue.size(); q_size > 0; --q_size) {
                auto top{queue.front()}; queue.pop();
                for(auto c{'a'}; c <= 'z'; ++c) {
                    top += c;
                    if(dictionary.end() != dictionary.find(top)) queue.push(top);
                    top.pop_back();
                }
            }
        }
        return result;
    }
};
