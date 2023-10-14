// https://leetcode.com/problems/palindrome-pairs/solutions/2585633/c-brute-hashmap-trie-tle-fixed/
class Solution {
public:
    // TC: O(W * L^2)
    // SC: O(W * L)
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode suffix_trie(this);
        for(int i = 0; i < words.size(); ++i) suffix_trie.insert(words[i], i);

        vector<vector<int>> result;
        for(int i = 0; i < words.size(); ++i) {
            const auto& word = words[i];
            auto node = &suffix_trie;
            const auto word_size{word.size()};
            for(int j = 0; j < word_size; ++j) {
                // "sp" | "ps" and  "sp" | "s" -> Check if suffix of the current word is palindrome
                // Also, handles {palindrome word, ""}
                if(-1 != node->word_index && i != node->word_index && isPalindrome(word, j, word_size - 1)) result.push_back({i, node->word_index});
                node = node->children[word[j] - 'a'];
                if(nullptr == node) break;
            }
            if(nullptr == node) continue;
            // "sp" | "xps" -> Check if last trie node has palindrome prefixes
            // Also, handles {"", palindrome word}
            for(const auto& palindrome_prefix : node->palindromePrefixes) if(i != palindrome_prefix) result.push_back({i, palindrome_prefix});
        }
        return result;
    }
private:
	bool isPalindrome(const string& str, int start, int end) {
		while(start < end) if(str[start++] != str[end--]) return false;
		return true;
	}
	
	struct TrieNode {
		TrieNode(Solution* solution = nullptr) : solution(solution) {}
		void insert(const string& word, int word_index) {
			auto curr = this;
			for(int i = word.size() - 1; i >= 0; --i) {
				if(true == solution->isPalindrome(word, 0, i)) curr->palindromePrefixes.push_back(word_index);
				const auto character{word[i] - 'a'};
				if(nullptr == curr->children[character]) curr->children[character] = new TrieNode;
				curr = curr->children[character];
			}
			curr->word_index = word_index;
			curr->palindromePrefixes.push_back(word_index);
		}
		int word_index = -1;
		vector<int> palindromePrefixes;
		struct TrieNode* children[26] = {0};
        Solution* solution{nullptr};	// To access isPalindrome() method
	};
};


// https://leetcode.com/problems/palindrome-pairs/solutions/79210/the-easy-to-unserstand-java-solution
class Solution2 {
public:
    // TC: O(W * L^2)
    // SC: O(W * L)
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> word_indexes;
        for(auto i = 0; i < words.size(); ++i) word_indexes[words[i]] = i;

        vector<vector<int>> result;
        for(auto i = 0; i < words.size(); ++i) {
            const auto& word = words[i];
            if("" == word) continue;
            auto reversed_word = word;
            reverse(reversed_word.begin(), reversed_word.end());
            if(auto it = word_indexes.find(reversed_word); it != word_indexes.end() && i != it->second) result.push_back({i, it->second});
            if(auto it = word_indexes.find(""); word_indexes.end() != it && true == isPalindrome(word)) {
                result.push_back({i, it->second});
                result.push_back({it->second, i});
            }
            const int word_size = word.size();
            for(int s = 1; s < word_size; ++s) {
                auto prefix = word.substr(0, s);
                auto suffix = word.substr(s);
                auto reversed_prefix = prefix;
                reverse(reversed_prefix.begin(), reversed_prefix.end());
                auto reversed_suffix = suffix;
                reverse(reversed_suffix.begin(), reversed_suffix.end());
                if(auto it = word_indexes.find(reversed_suffix); isPalindrome(prefix) && it != word_indexes.end()) result.push_back({it->second, i});
                if(auto it = word_indexes.find(reversed_prefix); isPalindrome(suffix) && it != word_indexes.end()) result.push_back({i, it->second});
            }
        }
        return result;
    }
private:
    bool isPalindrome(const string& str){
        for(int start = 0, end = str.size() - 1; start < end; ++start, --end) if(str[start] != str[end]) return false;
        return true;
    }
};
