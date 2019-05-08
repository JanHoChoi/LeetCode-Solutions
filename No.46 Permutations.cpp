class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res; 
        helper(res,nums,0);
        return res;
    }
    void helper(vector<vector<int> >&res, vector<int> nums, int i){
        if(i == nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int j = i; j < nums.size(); j++){
            swap(nums[j],nums[i]);
            helper(res,nums,i+1);
        }
    }
};