class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int> > dp(n,vector<int>(n,0)); // dp[i][j] = 1 表示从i-j是回文
        int count = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(s[i] == s[j]){
                    if(i - j == 1 || i - j == 2 || dp[j+1][i-1] == 1){
                        dp[j][i] = 1; // i和j相邻 或 隔一个字符 是回文
                        count++;
                    }
                }
            }
        }
        return count;
    }
};