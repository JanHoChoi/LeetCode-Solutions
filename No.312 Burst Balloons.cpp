class Solution {
public:
    // dp[left][right]表示left~right这一段中，最大的结果（不管是什么方式取到的）
    // 设想，选定一个[left,right]的区间后，再选定一个点i最后消除。
    // 因为i是最后消除的，所以对于[left,i-1]和[i+1,right]这两个区间的结果没有影响。
    // 而且区间里的值对i也没有影响，因为两个区间的数都爆完了。
    // 所以有dp[left][right] = dp[left][i-1]+dp[i+1][right]+nums[i]*nums[left-1]*nums[right+1]
    // 由这个式可以看出，我们需要先知道 小范围的值left~i-1和i+1~right，才可以推出大范围的值。
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1); // 前面补1
        nums.push_back(1); // 后面补1
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        for(int len = 1; len <= n; len++){
            for(int left = 1; left <= n - len + 1; left++){ // 注意取值范围(nums已经加了两个值了)
                int right = left + len - 1;
                for(int i = left; i <= right; i++){
                    dp[left][right] = max(dp[left][right], 
                        dp[left][i-1]+dp[i+1][right]+nums[i]*nums[left-1]*nums[right+1]);
                }
            }
        }
        return dp[1][n];
    }
};