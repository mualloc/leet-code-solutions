class Solution {
/*public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minNumCoins(amount + 1, amount + 1);
        minNumCoins[0] = 0;
        
        //for(int i = 1; i <= amount; i++){
        for(int coin : coins){
            //for(int coin : coins){
            for(int i = coin; i <= amount; i++){
                if(coin <= i){
                    minNumCoins[i] = min(minNumCoins[i], minNumCoins[i - coin]  + 1);
                }
            }
        }      
        return minNumCoins[amount] == amount + 1 ? -1 : minNumCoins[amount];
    }*/

    
public:
    // NOTE: I think time complexity is O(coins.length * amount)
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0) return -1;
        if(0 == amount) return 0;
        if(cache.find(amount) != cache.end()) return cache[amount];
        
        int minNumOfCoins = INT_MAX;   
        for(int coin : coins){
             int numOfCoins = coinChange(coins, amount-coin);
             if(numOfCoins < 0){
                 continue;
             }
            minNumOfCoins = std::min(numOfCoins + 1, minNumOfCoins);
        }
        
        minNumOfCoins == INT_MAX ? cache[amount] = -1 : cache[amount] = minNumOfCoins;
        return cache[amount];
    }
    
private:
    unordered_map<int, int> cache;
};