class Solution {
public:
    int climbStairs(int n) {
        if (n==1)
            return 1;
        if (n==2)
            return 2;
        int first = 1;
        int second = 2;
        int sum;
        int res = 0;
        int i = 2;
        while(i < n){
            sum = first+second;
            first = second;
            second = sum;
            i++;
        }
        return second;
    }
};