// https://leetcode.com/problems/fruit-into-baskets/solutions/170745/problem-longest-subarray-with-2-elements/
class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    int totalFruit(vector<int>& fruits) {
        // a, b, a,| b, b, b, c
        int result{0}, curr{0}, count_b{0}, a{0}, b{0};
        for(const auto& fruit : fruits) {
            curr = fruit == a || fruit == b ? curr + 1 : count_b + 1;
            count_b = fruit == b ? ++count_b : 1;
            if(fruit != b) a = b, b = fruit;
            result = max(result, curr);
        }
        return result;
    }
};


class Solution2 {
public:
    // TC: O(N)
    // SC: O(N)
    int totalFruit(vector<int>& fruits) {
        int result{0};
        vector<int> gathered(fruits.size(), 0);
        for(int left{0}, right{0}, curr{0}, fruit_types{0}; right < fruits.size(); ++right) {
            if(0 == gathered[fruits[right]]++) ++fruit_types;
            while(3 == fruit_types) {
                if(0 == --gathered[fruits[left++]]) --fruit_types;
                --curr;
            }
            result = max(result, ++curr);
        }
        return result;
    }
};


class Solution3 {
public:
    // TC: O(N)
    // SC: O(1)
    int totalFruit(vector<int>& fruits) {
        int result{0};
        unordered_map<int, int> gathered;
        for(int left{0}, right{0}, curr{0}; right < fruits.size(); ++right) {
            ++gathered[fruits[right]];
            while(3 == gathered.size()) {
                if(auto it = gathered.find(fruits[left++]); 0 == --(it->second)) gathered.erase(it);
                --curr;
            }
            result = max(result, ++curr);
        }
        return result;
    }
};
