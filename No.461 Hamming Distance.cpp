// #include<queue>
// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         queue<int> q_x,q_y;
//         while(x!=0){
//             q_x.push(x%2);
//             x /= 2;
//         }
//         while(y!=0){
//             q_y.push(y%2);
//             y /= 2;
//         }
//         int res = 0;
//         while(!q_x.empty() && !q_y.empty()){
//             if(q_x.front() != q_y.front())
//                 res ++;
//             q_x.pop();
//             q_y.pop();
//         }
//         while(!q_x.empty()){
//             if(q_x.front()==1)
//                 res++;
//             q_x.pop();
//         }
//         while(!q_y.empty()){
//             if(q_y.front()==1)
//                 res++;
//             q_y.pop();
//         }
//         return res;
//     }
// };

class Solution {
public:
    int hammingDistance(int x, int y) {
        // 先异或 再判断结果有多少个1
        int z = x ^ y;
        int res = 0;
        while(z!=0){
            if(z%2 == 1)
                res++;
            z /= 2;
        }
        return res;
    }
};

