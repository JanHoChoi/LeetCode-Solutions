class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> res(n,1);
        for(int i = 0; i < m-1; i++){ // 从第二行开始遍历到最后一行 一共m-1次
            for(int j = 1; j < n; j++){
                // 每次遍历替换除了res[0]以外的元素
                // 到A点的路径数 = 到A点左边的路径数 + 到A点上边的路径数
                res[j] += res[j-1];
            }
        }
        return res[n-1];
    }
};