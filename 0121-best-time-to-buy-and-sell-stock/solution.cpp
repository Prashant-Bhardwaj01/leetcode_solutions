class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int small = prices[0];
        int max_profit = 0;
        for(int i=1;i<prices.size();i++){
            if(small<prices[i]){
                max_profit = max(max_profit, prices[i] - small);
            }
            small = min(small,prices[i]);
        }
        return max_profit;
    }
};
