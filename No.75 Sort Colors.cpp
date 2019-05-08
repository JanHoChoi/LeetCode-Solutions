class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, p = 0, two = nums.size()-1;
        while(p <= two){
            if(nums[p] == 1)
                p++;
            else if(nums[p] == 0){
                swap(nums[zero],nums[p]); // 可以保证nums[zero]之前不包括nums[zero]的都是0
                zero++;
                p++;
            }
            else{
                swap(nums[p],nums[two]);
                two--; // 这里p不能++，因为不确定nums[two]换过来的东西是什么。
                // 如果这里也p++，那么nums[two]换过来的东西，就不会被nums[p]检验。
            }
        }
        return;
    }
};