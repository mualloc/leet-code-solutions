class Solution2 {
public:
    // TC: O(s * 26)
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        vector<int> pCount(26);
        vector<int> sCount(26);
        for(int i = 0; i < p.size(); ++i){
            ++pCount[p[i] - 'a'];
            ++sCount[s[i] - 'a'];
        }
            
        vector<int> result;
        int left = 0, right = p.size() - 1;
        do{
            if(pCount == sCount) result.push_back(left);
            --sCount[s[left++] - 'a'];
            if(++right < s.size()) ++sCount[s[right] - 'a'];
        }while(right < s.size());
        
        return result;
    }
    
    // TC: O(s * 26)
    vector<int> findAnagrams2(string s, string p) {
        unordered_map<char, int> pCount;
        unordered_map<char, int> sCount;
        for(const char & c : p) ++pCount[c];
        for(int i = 0; i < p.size(); ++i) ++sCount[s[i]];
        
        vector<int> result;
        int left = 0, right = p.size() - 1;
        do{
            if(pCount == sCount) result.push_back(left);
            --sCount[s[left]];
            if(0 == sCount[s[left]]) sCount.erase(s[left]);
            ++left; ++right;
            ++sCount[s[right]];
        }while(right < s.size());
        
        return result;
    }      
};


class Solution {
public:
    // TC: O(s)
    vector<int> findAnagrams(string s, string p) {  
        if(p.size() > s.size()) return {};
        vector<int> pCount(26, 0);
        int count = 0;
        for(const char c : p) {
            if(0 == pCount[c -'a']++) ++count;
        }
                
        vector<int> result;
        for(int end = 0, start = 0; end < s.size(); end++){
            if(0 == --pCount[s[end] - 'a']){
                if(0 == --count) result.push_back(start); 
            }
            if(end - start + 1 == p.size()) {
                if(pCount[s[start++] - 'a']++ == 0) ++count;
            }
        }      
        return result;
    }
};