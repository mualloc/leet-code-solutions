class Solution2 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t leftMask = 1 << 31, rightMask = 1;
        
        for(size_t i = 0; i < 32; ++i){
            if(n & rightMask) result |= leftMask;
            rightMask <<= 1, leftMask >>=1;
        }
        return result;
    }
};


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(size_t i = 0; i < 32; ++i){
            result = result << 1 | n & 1;
            n >>= 1;
        }  
        return result;
    }
};