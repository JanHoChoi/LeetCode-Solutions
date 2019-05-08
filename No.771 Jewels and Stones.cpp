#include<string>
#include<unordered_set>

using namespace std;

// class Solution {
// public:
//     int numJewelsInStones(string J, string S) {
//         int res = 0;
//         unordered_set<char> dict(J.begin(),J.end());
//         for(char s : S){
//             if(dict.find(s)!=dict.end())
//                 res++;
//         }
//         return res;
//     }
// };
// 用了STL:unordered_set的方法
// 效果貌似不如直接用数组

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int dict[52];
        for(int i = 0; i < 52; i++)
            dict[i] = 0;
        int res = 0;
        for(int i = 0; i < J.size(); i++){
            if(J[i] >= 'a')
                dict[J[i]-'a'] = 1;
            else
                dict[J[i]-'A'+26] = 1;
        }
        for(int i = 0; i < S.size(); i++){
            if(S[i] >= 'a'){
                if(dict[S[i]-'a'] == 1)
                    res++;
            }
            else{
                if(dict[S[i]-'A'+26] == 1)
                    res++;
            }
        }
        return res;
    }
};