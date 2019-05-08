class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int res = 0;
        while(left < right){
            if(height[left] < height[right]){
                res = max(res,(right-left)*height[left]); // 如果左边小，那么只能向右找更长
                left++;
            }
            else{
                res = max(res,(right-left)*height[right]);
                right--;
            }
        }
        return res;
    }
};