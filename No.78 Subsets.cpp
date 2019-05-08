class Solution {
public:
    // 递归+回溯
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int> > res;
    //     vector<int> temp;
    //     res.push_back(temp);
    //     helper(res,temp,nums,0);
    //     return res;        
    // }
    // void helper(vector<vector<int> > &res, vector<int> temp, vector<int>& nums, int cur){
    //     for(int i = cur; i < nums.size(); i++){
    //         temp.push_back(nums[i]);
    //         res.push_back(temp);
    //         helper(res,temp,nums,i+1);
    //         temp.pop_back();
    //     }
    //     return;
    // }

    // 迭代
    vector<vector<int>> subsets(vector<int> & nums){
        vector<vector<int>> res;
        res.push_back(vector<int>());
        for(int i = 0; i < nums.size(); i++){
            int size = res.size();
            for(int j = 0; j < size; j++){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};