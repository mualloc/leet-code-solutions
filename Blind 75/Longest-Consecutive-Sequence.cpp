// NOTE: BUNU ANLA!!!!!!!
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_map<int,int> seqLengths;
        for(const int & num : nums){
            if(0 == seqLengths[num]){
                int seqLength = 1 + seqLengths[num - 1] + seqLengths[num + 1];
                seqLengths[num] = seqLength;
                seqLengths[num + seqLengths[num + 1]] = seqLength;
                seqLengths[num - seqLengths[num - 1]] = seqLength;
                if(seqLength > result) result = seqLength;
            }
        }
        
        return result;
    }
};


class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
             
        int result = 0;
        for(auto it = set.begin(); it != set.end(); ++it){
            // Check if it is the start of a sequece
            if(set.end() == set.find(*it - 1)){
                int currCount = 1;
                while(set.end() != set.find(*it + currCount)) ++currCount;
                if(currCount > result) result = currCount;    
            }  
        }     
        return result;
    }
};


class Solution3 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        
        int result = 0;
        for(const int & num : nums){
            if(set.end() != set.find(num)){
                int prev = num, next = num;
                set.erase(num);
                while(set.end() != set.find(prev - 1)) set.erase(--prev);
                while(set.end() != set.find(next + 1)) set.erase(++next);
                result = max(result, next - prev + 1);
                if(0 == set.size()) break;
            }
        }
        
        return result;
    }
};