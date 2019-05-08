class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> temp;
        int sum = 0, res = 0;
        temp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            res += temp[sum-k];
            temp[sum] += 1;
        }
        return res;
    }
};