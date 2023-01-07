class Solution {
public:
    // https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        int counter = t.size();
        int begin = 0, end = 0, head = 0;
        int d = INT_MAX;
        
        for(char c: t) ++map[c];
        
        while(end < s.size()){
            if(map[s[end++]]-- > 0) --counter;
            while(0 == counter){    // valid
                if(end - begin < d) d = end - (head = begin);
                if(map[s[begin++]]++ == 0) ++counter;   // Make it invalid
            }
        } 
        
        return INT_MAX == d ? "" : s.substr(head, d);
    }
      
/*public:
    string minWindow(string s, string t) {
        vector<int> curr(128, 0);
        vector<int> needed(128, 0);

        for(char & c : t)   ++needed[c - 'A'];
        
        int left = 0, right = 0;
        const int neededCount = t.size(); 
        int haveCount = 0;
        int resLeft = 0, resRight = INT_MAX;
        
        while(right < s.size()){
            if(0 != needed[s[right] - 'A']){
                curr[s[right] - 'A']++;
                if(needed[s[right] - 'A'] >= curr[s[right] - 'A']) {                    
                    haveCount++;
                }
                while(haveCount == neededCount){
                    if(resRight - resLeft > right - left){
                        resRight = right;
                        resLeft = left;
                    }
                    if(curr[s[left] - 'A'] > 0){
                        --curr[s[left] - 'A'];
                        if(curr[s[left] - 'A'] < needed[s[left] - 'A']) --haveCount;
                    }
                    left++;
                }
            }
            right++;
        }
        return INT_MAX == resRight ? "" : s.substr(resLeft, resRight - resLeft + 1);
    }*/
/*************************************************************************************************/    

/*public:
    string minWindow(string s, string t) {
        unordered_map<char, int> curr;
        unordered_map<char, int> needed;
        
        for(char & c : t)   needed[c]++;
        
        int left = 0, right = 0;
        const int neededCount = needed.size();      // NOTE: Not t.size()!
        int haveCount = 0;
        int resLeft = 0, resRight = INT_MAX;
        
        while(right < s.size()){
            if(needed.end() != needed.find(s[right])){
                curr[s[right]]++;
                if(needed[s[right]] == curr[s[right]]) {                    
                    haveCount++;
                }
                while(haveCount == neededCount){
                    if(resRight - resLeft > right - left){
                        resRight = right;
                        resLeft = left;
                    }
                    if(curr.end() != curr.find(s[left])){
                        --curr[s[left]];
                        if(curr[s[left]] < needed[s[left]]) --haveCount;
                    }
                    left++;
                }
            }
            right++;
        }
        return INT_MAX == resRight ? "" : s.substr(resLeft, resRight - resLeft + 1);
    }*/
    
/*public:
    string minWindow(string s, string t) {
        int totalFound = 0;
        for(const auto & c : t){
            charCounts[c].second++;
        }
        int currLeftIndex = 0, currRightIndex = INT_MAX;
        int left = 0, right = 0;
        
        while(right < s.size() || left < s.size()){
            while(right < s.size()){
                if(charCounts.end() != charCounts.find(s[right])){
                    charCounts[s[right]].first++;
                    if(charCounts[s[right]].first <= charCounts[s[right]].second) totalFound++;
                    
                    if(totalFound == t.size()){
                        if(right - left < currRightIndex - currLeftIndex){
                            currRightIndex = right;
                            currLeftIndex = left;
                        }
                        break;
                    }                    
                }
                right++;
            }
            
            while(++left < s.size()){
                if(charCounts.end() != charCounts.find(s[left - 1])){
                    if(charCounts[s[left - 1]].first <= charCounts[s[left - 1]].second) totalFound--;
                    charCounts[s[left - 1]].first--;
                }
               
                if(totalFound == t.size()){
                    if(right - left < currRightIndex - currLeftIndex){
                        currRightIndex = right;
                        currLeftIndex = left;
                    }    
                }else break;                
            }
            right++;
        }
        
        if(INT_MAX == currRightIndex) return "";
        else return s.substr (currLeftIndex, currRightIndex - currLeftIndex + 1);    
    }
    
private:
    unordered_map<char, pair<int, int>> charCounts;     // char in t, <current amount in s, required amount determined via t>*/
/*************************************************************************************************/    
    
/*public:
    string minWindow(string s, string t) {
        for(auto c : t){
            charCounts[c]++;
        }
        int currLeftIndex = 0, currRightIndex = INT_MAX;
        int left = 0, right = 0;
        
        while(right < s.size() || left < s.size()){
            while(right < s.size()){
                if(charCounts.end() != charCounts.find(s[right])){
                   --charCounts[s[right]];
                    if(true == isSubstring()){
                        if(right - left < currRightIndex - currLeftIndex){
                            currRightIndex = right;
                            currLeftIndex = left;
                        }
                        break;
                    }                    
                }
                right++;
            }
            
            while(++left < s.size()){
                if(charCounts.end() != charCounts.find(s[left - 1])){
                    ++charCounts[s[left - 1]];
                }
                //left++;                
                if(true == isSubstring()){
                    if(right - left < currRightIndex - currLeftIndex){
                        currRightIndex = right;
                        currLeftIndex = left;
                    }    
                }else break;                
            }
            right++;
        }
        if(INT_MAX == currRightIndex) return "";
        else return s.substr (currLeftIndex, currRightIndex - currLeftIndex + 1);    
    }
    
private:
    bool isSubstring(){
        for (auto& it: charCounts) 
            if(it.second > 0) return false;
        return true;
    }
        
    unordered_map<char, int> charCounts;*/
};