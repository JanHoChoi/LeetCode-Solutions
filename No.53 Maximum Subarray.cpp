class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.begin(), nums.end()); // 如果只有一个数 那最大子集就是自己
        int n = nums.size();
        int res = dp[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(dp[i], nums[i]+dp[i-1]); // 判断前面传来的数加上自己后，对自己是否有利，始终选择最有利的操作。
            res = max(res,dp[i]);
        }
        return res;
    }
};