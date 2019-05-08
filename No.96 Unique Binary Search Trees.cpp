class Solution {
public:
    // 思路：如果我们把n作为根节点，那么所以小于n的数，都会被放在左边，大于n的数都会被放在n的右边。
    // 如果总共是1~n，根节点为i，左边有k-1个数G(i-1)，右边有n-k个数G(n-i)
    // 所以是F(i,n)表示i为根节点，一共有n个值
    // F(i,n) = G(i-1)*G(n-i); G(n) = F(1,n) + F(2,n) + F(3,n) + ... + F(n,n)
    // 化简一下，发现G(n) = G(0)*G(n-1) + G(1)*G(n-2) + ... + G(n-1)*G(0)
    int numTrees(int n) {
        vector<int> res(n+1,0);
        res[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                res[i] += res[j] * res[i-j-1];
            }
        }
        return res[n];
    }
};