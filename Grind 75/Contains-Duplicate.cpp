class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {             
        vector<unsigned char> posNumsBitSet(kPosNumsBitSetSize);
        vector<unsigned char> negNumsBitSet(kNegNumsBitSetSize);
        const unsigned char masks[] = {1, 2, 4, 8, 16, 32, 64, 128};
        
        const unsigned char shiftCountForByteIndex = log2(CHAR_BIT);  // Will be used to determine index of byte      
        for(const int & num : nums){
            const int byte = abs(num) >> shiftCountForByteIndex;     // Divides by 8
            const int bit = abs(num) & (CHAR_BIT - 1);              // 'CHAR_BIT - 1' effectively means to be '7' used for finding remainder
            const unsigned char mask = masks[bit];
            
            if(num >= 0){
                if(num / CHAR_BIT >= posNumsBitSet.size()) posNumsBitSet.resize(num / (CHAR_BIT / 2));  // Effectively doubling size up
                if(posNumsBitSet[byte] & mask) return true;
                else posNumsBitSet[byte] |= mask;
            }
            else{
                if(abs(num) / CHAR_BIT >= negNumsBitSet.size()) negNumsBitSet.resize(abs(num) / (CHAR_BIT / 2));    // Effectively doubling size up
                if(negNumsBitSet[byte] & mask) return true;
                else negNumsBitSet[byte] |= mask;
            }
        }

        return false;
    }

    bool containsDuplicate2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) if(nums[i] == nums[i + 1]) return true;
        return false;
    }
    
    bool containsDuplicate3(vector<int>& nums) {
        unordered_set<int> set;
        //set.reserve(nums.size());
        for(const int & num : nums){
            if(false == set.insert(num).second) return true;
        }
        return false;
    }

    bool containsDuplicate4(vector<int>& nums) {
        return nums.size() > unordered_set(nums.begin(), nums.end()).size();
    }
    
private:
    enum InitialSizes{
        kPosNumsBitSetSize = 1 << 10,
        kNegNumsBitSetSize = 1 << 10
    };
};