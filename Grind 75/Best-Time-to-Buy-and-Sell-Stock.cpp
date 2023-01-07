class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int min = INT_MAX;
        
        for(const int & price : prices){
            if(min > price) min = price;
            else result = max(result, price - min);
        }
        
        return result;
    }
};