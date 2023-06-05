// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/75927/share-my-thinking-process/comments/173646
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int sell = 0, buy = -prices[0], cooldown = 0;
        for(int i = 1; i < prices.size(); ++i){
            int prev_sell = sell;
            sell = max(sell, buy + prices[i]);
            buy = max(buy, cooldown - prices[i]);
            cooldown = max(cooldown, prev_sell);
        }
        return max(sell, cooldown);
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int sell = 0, buy = -prices[0], prev_sell = 0;
        for(int i = 1; i < prices.size(); ++i){
            int temp = sell;
            sell = max(sell, buy + prices[i]);
            buy = max(buy, prev_sell - prices[i]);
            prev_sell = temp;
        }
        return sell;
    }
};
