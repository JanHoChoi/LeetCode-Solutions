class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            res ^= nums[i];
        }
        return res;
    }
};

// 一个很trick的方法 因为两个相同的数异或为0