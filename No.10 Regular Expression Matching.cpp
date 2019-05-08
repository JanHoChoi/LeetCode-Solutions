class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        // 如果p[1]是*
        // 那么① 无论p[0]和s[0]是否匹配, 只要p[2...]与s可以match即可, 此时*当做0次使用.
        // ② p[0]与s[0]匹配 则只要p与s[1...]可以match即可, *当做1次使用(*在后面还可以继续用).
        if(p[1] == '*')
            return isMatch(s,p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1),p);
        
        // 如果p[1]不是*
        // 那么必须要p[0]与s[0]匹配 且s[1...]与p[1...]匹配
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1),p.substr(1));
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        // dp[i][j] 表示s[0...i-1] 与p[0...j-1]匹配
        vector<vector<bool> > dp(m+1, vector<bool>(n+1,false));

        // 初始化基本条件
        dp[0][0] = true; // 都为空true
        for(int i = 1; i <= m; i++){
            dp[i][0] = false; // s不为空 p为空 false
        }
        for(int j = 1; j <= n; j++){
            // 如果p[j-1]为*，且p[0...j-2]可以与空s匹配,那么true
            // 注意dp[0][1]一定为false
            dp[0][j] = j > 1 && dp[0][j-2] && p[j-1] == '*'; 
        }

        // 开始动态规划
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){

                // p[j-1]是*, 则要么
                // ①p[0...j-3]与s[0..i-1]匹配 此时*让p[j-2]使用0次
                // ②p[0...j-2]与s[0..i-1]匹配 即p[j-2]与s[i-1]匹配 且s[0...i-2]与p[0...j-3]匹配 即dp[i-1][j-2]
                // 又因为p[j-1]是*，所以即要dp[i-1][j]为true 此时*让p[j-2]使用1次以上
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && dp[i-1][j];
                }

                // 如果p[j-1]不是*
                // 则只能让p[j-1]与s[i-1]匹配, 且p[0...j-2]与s[0...i-2]匹配
                else{
                    dp[i][j] = dp[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '.');
                }
            }
        }

        return dp[m][n];
    }
};