// 迭代
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0 || x == 1) return x; // 特殊情况直接处理掉
        double res = 1;
        long long count = n; // 避免n=INT_MIN时无法直接取负 先处理成ll类型
        if(n < 0){
            x = 1/x;
            count = -count;
        }
        double temp = x;
        while(count){
            if(count & 1)
                res *= temp;
            temp *= temp;
            count >>= 1;
        }
        return res;
    }
};

// 递归
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(x == 0 || x == 1) return x; // 特殊情况直接处理掉
        double temp = myPow(x,n/2);
        if(n%2 == 0) return temp*temp;
        else return (n<0)? 1/x*temp*temp : x*temp*temp;
    }
};