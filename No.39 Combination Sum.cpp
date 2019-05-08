class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> answer;
        helper(res,answer,candidates,target,0);
        return res;
    }
    void helper(vector<vector<int>>& res,vector<int>  answer, vector<int> & candidates, int target, int position){
        if(target == 0){
            res.push_back(answer);
            return;
        }
        for(int i = position; i < candidates.size(); i++){
            if(candidates[i] <= target){
                answer.push_back(candidates[i]);
                helper(res,answer,candidates,target-candidates[i],i);
                answer.pop_back();
            }
            else
                return;
        }
    }
};