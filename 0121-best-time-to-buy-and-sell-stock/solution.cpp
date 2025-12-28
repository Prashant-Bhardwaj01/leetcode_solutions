class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int left = 0;
        int right = 1;
        while(right < prices.size()){
            if(prices[right] > prices[left]) ans = max(ans,prices[right] - prices[left]);
            else left = right;
            right++;
        }
        return ans;
    }
};
