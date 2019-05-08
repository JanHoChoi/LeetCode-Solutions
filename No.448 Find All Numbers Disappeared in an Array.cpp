class Solution {
public:
    // 特殊的思路 有出现过和没出现过两种选项 如果出现过 则让对应的位置的值变为负数
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(auto i : nums){
            int temp = abs(i)-1;
            nums[temp] = nums[temp] > 0? -nums[temp] : nums[temp]; // 把对应位置变为负
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
    }
};