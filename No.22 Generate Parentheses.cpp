class Solution {
public:
    // 递归写法
    // vector<string> generateParenthesis(int n) {
    //     vector<string> res;
    //     helper(res,"",n,0);
    //     return res;
    // }
    // void helper(vector<string>& res, string temp, int left, int right){
    //     if(left == 0 && right == 0){
    //         res.push_back(temp); // 左右括号都已经放完了
    //         return;
    //     }
    //     if(right > 0)
    //         helper(res,temp+")",left,right-1); // 如果右可以放 先放右
    //     if(left > 0)
    //         helper(res,temp+"(",left-1,right+1); // 放了一个左 则左减少一个 可以放的右增加一个
    // }
    
    // 非递归 假设我们知道f(1) f(2) ... f(n-1), 要得到f(n), 则可以这样做
    // ( f(x) ) + f(y) 其中x+y = n-1 这样一来 总括号刚好为n对 且每种组成都不重复
    // 还可以证明 完全性
    // f(n)中任意一种答案 它的最左边肯定是左括号，这个左括号也有对应的右括号
    // 把这一对提出来 中间的东西 必是f(x)之一 外面的东西 必是f(y)之一
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > res(n+1);
        res[0].push_back("");
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < i; j++)
                for(auto p : res[j])
                    for(auto q : res[i-j-1])
                        res[i].push_back("("+p+")"+q);
        return res[n];
    }
};