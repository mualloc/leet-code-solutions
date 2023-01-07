class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        for(unsigned i = 0, mask = 1; i < 32; i++, mask <<= 1) { // Note the unsigned type of `i`!!
            int bitCount = 0;
            for(int num : nums){
                if(num & mask) bitCount++;
            }
            if(bitCount > nums.size() / 2){
                majority |= mask;
            }
        }
        return majority;
    }

    /*int majorityElement(vector<int>& nums) {
        int count = 0, element = 0;

        for(const int & num : nums){
            if(0 == count) element = num;
            count += num == element ? 1 : -1;
        }
        return element;
    }*/
     
    /*int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int target = nums.size() / 2 + 1;
        
        for(const int & num : nums){
            if(target == ++freq[num]) return num;            
        }
        return -1;
    }*/
};