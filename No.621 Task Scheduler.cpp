class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(auto c : tasks)
            count[c-'A']++; // 先统计每个任务出现的次数
        int m = 0; // m是出现次数最多的任务
        for(auto i : count)
            m = max(m,i);

        int res = (m-1) * (n+1); // 出现m次，那么起码要有m个大间隙
        for(auto i : count){
            if(i == m)
                res++; // 如果是出现m次的字母，会在最后再来一次。
        }
        // 如果空隙一次不够放所有字母的话,其实可以随机找位置放剩下的字母。
        return max(res,tasks.size());
    }
};