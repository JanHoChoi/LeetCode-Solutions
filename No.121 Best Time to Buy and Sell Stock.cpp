class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0; // 异常处理
        int buy = prices[0];
        int res = 0;
        for(int i = 0; i < n; i++){
            buy = min(prices[i],buy);
            res = max(prices[i]-buy,res); // 保证了sell一定在buy之后
        }
        return res;
    }
};