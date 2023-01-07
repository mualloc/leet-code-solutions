class Solution {
public:
    // NOTE: Bottom-up
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        int prev = 1; // f(1)
        int current = 2; // f(2)        
        for(int i = 3, nextPrev = 0; i <= n; i++){
            nextPrev = current;
            current = prev + current;
            if(n == i) break;
            prev = nextPrev;
        }
        return current;
    }
    
    /*Solution(){
        memset(cache, -1, sizeof(cache));
        //cache[0] = 1;        
        cache[1] = 1;
        cache[2] = 2;
    }
 
    // NOTE: Top down
    int climbStairs(int n) {
        if(-1 != cache[n]) return cache[n];              
        cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return  cache[n];      
    }
    
private:
    int cache[46];*/
};