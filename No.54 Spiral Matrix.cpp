class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if(!row) return res;
        int col = matrix[0].size();
        int top = 0, down = row - 1, left = 0, right = col - 1; // 标记了4个边界
        int i = 0, j = 0;
        while(1){
            // 向右走
            while(j <= right){
                res.push_back(matrix[i][j]);
                j++;
            }
            j--;
            top += 1;
            if(++i > down) break;

            // 向下走
            while(i <= down){
                res.push_back(matrix[i][j]);
                i++;
            }
            i--;
            right -= 1;
            if(--j < left) break;

            // 向左走
            while(j >= left){
                res.push_back(matrix[i][j]);
                j--;
            }
            j++;
            down -= 1;
            if(--i < top) break;

            // 向上走
            while(i >= top){
                res.push_back(matrix[i][j]);
                i--;
            }
            i++;
            left += 1;
            if(++j > right) break;

        }
        return res;
    }
};