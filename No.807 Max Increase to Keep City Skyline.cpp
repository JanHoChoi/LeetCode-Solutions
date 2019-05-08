#include <vector>
using namespace std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int> >& grid) {
        int length = grid.size();
        vector<vector<int> > skyline(2,vector<int>(length,0));
        for(int x = 0; x < length; x++){
            for(int y = 0; y < length; y++){
                skyline[0][x] = max(skyline[0][x],grid[x][y]);
                skyline[1][y] = max(skyline[1][y],grid[x][y]);
            }
        }
        int res = 0;
        for(int x = 0; x < length; x++){
            for(int y = 0; y < length; y++){
                res += min(skyline[0][x],skyline[1][y]) - grid[x][y];
            }
        }
        return res;
    }
};