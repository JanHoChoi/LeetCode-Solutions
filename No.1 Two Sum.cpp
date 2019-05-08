class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> result(2,0);
        for(int i = 0; i < nums.size(); i++){
            if(hash[target-nums[i]]>0){
                result[0] = hash[target-nums[i]] - 1;
                result[1] = i;
                return result;
            }
            else
                hash[nums[i]] = i+1;
        }
        return result;
    }
};