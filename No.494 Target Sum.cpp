class Solution {
public:

    int helper(vector<int> & nums, int target){ // nums里面选一部分加起来为target
        vector<int> dp(target+1,0); // target <= 40000
        dp[0] = 1;
        for(int num : nums){
            for(int i = target; i >= num; i--){
                dp[i] += dp[i-num]; // dp[i-num]表示在num之前的数凑成(i-num)的总方法
            }
        }
        return dp[target];
    }
    // 假设sum(Positive) - sum(Negative) = target
    // 则 sum(P) - sum(N) + sum(P) + sum(N) = target + sum(nums)
    // 2sum(P) = target + sum(nums)
    // 变成了这个子问题
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum < S || (sum+S)%2 == 1)
            return 0;
        else
            return helper(nums, (sum+S)/2 );
    }
};