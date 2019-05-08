class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     return nums[nums.size()/2];
    // }
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int count = 1, major = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == major)
                count++;
            else if(count > 0)
                count--;
            else{
                major = nums[i];
                count = 1;
            }
        }
        if(count > 0) // 如果有解
            return major;
        else
            return -1;
    }
};