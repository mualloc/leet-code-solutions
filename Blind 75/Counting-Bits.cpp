class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for(size_t i = 1; i <= n; ++i) result[i] = 1 + result[i & i - 1];
        return result;
    }
};


class Solution2 {
public:
    // TC: O(n)
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        size_t offset = 1;
        for(size_t i = 1; i <= n; ++i){
            if(i == (offset << 1)) offset = i;                                              
            dp[i] = 1 + dp[i - offset];
        }
        return dp;
    }
};


class Solution3 {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for(size_t i = 0; i <= n; ++i) result[i] = result[i >> 1] + (i & 1);
        return result;
    }
};