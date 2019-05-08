// 桶排序 即相当于 设置n+1(n=数字个数) 个桶 (出现i次的数 放在第i个桶中 同个数字最多只有n次出现)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_map存储着所有数出现次数 first表示数字 second表示出现次数
        unordered_map<int,int> m;
        for(auto n : nums)
            m[n]++;
        vector<vector<int> > bucket(nums.size()+1);
        // 创建一个桶(每个桶为一个数组 可以放很多数) +1是避免所有数字一样
        for(auto i : m){
            bucket[i.second].push_back(i.first); // 出现i次的数字放在第i个桶中
        }
        vector<int> res(k);
        int count = 0;
        // 从大到小 取出那些出现最多的数
        for(int i = nums.size(); i >= 0; i--){
            for(auto j : bucket[i]){
                res[count++] = j;
                if(count == k)
                    return res;
            }  
        }
        return res;
    }
};