class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m<1)
            return;
        for(int i = 0; i < m/2; i++){
                swap(matrix[i],matrix[m-i-1]);
        }
        for(int i = 0; i < m; i++){
            for(int j = i+1; j < m; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        return;
    }
};