class Solution {
public:
    // 注意点：一天只能执行一种操作（不能同时买和卖）只能先买再卖（不能买两份/提前卖）
    // 而且卖了之后，需要暂停一天
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> s1(n,0),s2(n,0),s3(n,0); // s1表示未持有股票 s2表示已经持有股票 s3表示在冷却
        // 这个状态有丶巧妙，可以思考一下
        s2[0] = -prices[0];
        for(int i = 1; i < n; i++){
            s1[i] = max(s1[i-1],s3[i-1]);
            s2[i] = max(s1[i-1]-prices[i],s2[i-1]);
            s3[i] = s2[i-1]+prices[i];
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res,s3[i]);
        }
        return res;
    }
};