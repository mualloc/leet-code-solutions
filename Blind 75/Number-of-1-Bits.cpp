class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for( ; n; n &= n - 1, result++);
        return result;
    }
};


class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        unsigned char setBitCountTable[256];
        
        for(uint16_t i = 0; i < 256; ++i){
            setBitCountTable[i] = (i & 1) + setBitCountTable[i >> 1];
        }
        
        int result = 0;
        for(int i = 0; i < 4; ++i, n >>= 8) result += setBitCountTable[n & 0XFF];
        
        return result;
    }
};


class Solution3 {
public:
    int hammingWeight(uint32_t n) {
        if(0 == n) return setBitCountTable[0];
        return setBitCountTable[n & 0XF] + hammingWeight(n >> 4);
    }
    
private:
    const unsigned char setBitCountTable[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4}; 
};


class Solution4 {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for( ; n; n >>= 1) result += n & 1;      
        return result;
    }
};