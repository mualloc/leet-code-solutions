class Solution {
public:
    // TC: O(62*N)
    // SC: O(31*N)
    int findMaximumXOR(vector<int>& nums) {
        TrieNode trie;
        for(const auto& num : nums) trie.insert(static_cast<unsigned>(num));
        int result{0};
        for(const auto& num : nums) result = max(result, num ^ trie.getMaximumXORNum(num));
        return result;
    }
private:
	class TrieNode {
	public:
		void insert(auto num) {
			auto *curr{this};
			auto mask{1U << 31};
			for(auto i{0U}, negated{~num}; i < 31; ++i, mask >>= 1) {
				const auto bit{(negated & mask) > 0};
				if(nullptr == curr->children[bit]) curr->children[bit] = new TrieNode;
				curr = curr->children[bit];
			}
			curr->num = num;
		}
		int getMaximumXORNum(auto num) {
			auto *curr{this};
			auto mask{1U << 31};
			for(auto i{0U}; i < 31; ++i, mask >>= 1) {
				const auto bit{(num & mask) > 0};
				curr = curr->children[bit] ? curr->children[bit] : curr->children[!bit];
			}
			return curr->num;
		}
	private:
		TrieNode *children[2] = {};
		int num{};
	};
};


class Solution2 {
public:
    // TC: O(N^2)
    int findMaximumXOR(vector<int>& nums) {
        int result{0};
        for(int i{0}, nums_size = nums.size(); i < nums_size; ++i) 
            for(int j = i + 1; j < nums_size; ++j) 
                result = max(result, nums[i] ^ nums[j]);
        return result;
    }
};
