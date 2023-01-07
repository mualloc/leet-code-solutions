class Trie {
 public:
    void insert(const string & word) {
      Trie * current = this;
      for (char c: word) {
        if (nullptr == current -> children[c - 'a']) {
          current -> children[c - 'a'] = new Trie;
        }
        current = current -> children[c - 'a'];
      }
      current -> terminates = true;
    }

  bool contains(const string & word) {
    Trie * current = this;
    for (char c: word) {
      current = current -> children[c - 'a'];
      if (nullptr == current) return false;
    }
    return current -> terminates;
  }
private:
    Trie * children[26] = {0};
    bool terminates = false;
};


class Solution {
public:
    bool wordBreak(string s, vector < string > & wordDict) {
      for (size_t end = 0; end < s.size(); end++) {
        const string & currentS = s.substr(0, end + 1);
        for (const auto & word: wordDict) {
          if (endsWith(currentS, word)) {
            const string & prefix = s.substr(0, currentS.size() - word.size());
            if (0 == prefix.size() || trie.contains(prefix)) {
              trie.insert(currentS);
              break;
            }
          }
        }
      }
      return trie.contains(s);
    }

private:
    bool endsWith(const std::string & str, const std::string & suffix) {
        return str.size() >= suffix.size() && 0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
    }
    
    Trie trie;
};

/*class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        
        for(int start = s.size() - 1; start >= 0; --start){
            for(const auto & word : wordDict){
                if(word.size() <= s.size() - start){
                    if(true == dp[start + word.size()] && word == s.substr(start, word.size())){
                        dp[start] = true;
                        break;
                    }
                }
            }                
        }
        return dp[0];
    }
};*/


/*class Solution {
public:
    // BFS
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> visited(s.size(), false);
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        queue<int> queue;
        queue.push(0);
        visited[0] = true;
        
        while(false == queue.empty()){
            int start = queue.front(); queue.pop();
            
            string temp;
            for(int end = start; end < s.size(); ++end) {
                temp += s[end];
                if(words.end() != words.find(temp)){
                    int cand = end + 1;
                    if(cand == s.size()) return true;
                    if(false == visited[cand]){
                        queue.push(cand);
                        visited[cand] = true;
                    }
                }
            }
        }      
        return false;
    }
};*/


/*class Solution {
public: 
    // O(n^2) * O(look up of wordDict)
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return check(s, 0, words, memo);
    }
     
    int check(const string & s, int start, const unordered_set<string> & wordDict, vector<int> & memo){
        if(start == s.size()) return 1;
        if(-1 != memo[start]) return memo[start];
        
        for(int i = start + 1; i <= s.size(); i++){
            if(wordDict.end() != wordDict.find(s.substr(start, i - start)) && check(s, i, wordDict, memo)) {
                memo[start] = 1;
                return memo[start];
            }        
        }
        memo[start] = 0;
        return memo[start];
    }
};*/


/*class Solution {
public: 
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return canBrk(0,s,words);    
    }
    bool canBrk(int start, string& s, unordered_set<string>& wordDict) {
        int n = s.size();
        if(start == n) return 1;
        string sub;
        for(int i = start; i<n; i++) if(wordDict.count(sub+=s[i]) && canBrk(i+1,s,wordDict)) return 1;
        return 0;
    }
};*/