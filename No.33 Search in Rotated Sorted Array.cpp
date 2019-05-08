class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() < 1)
            return -1;
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > nums[right]){ // 有旋转 且mid在左边(较大边)
                if(target > nums[mid] || target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if(nums[mid] < nums[left]){ // 有旋转 且mid在右边(较小边)
                if(target < nums[mid] || target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else{ // 没有旋转
                if(target > nums[mid])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        if(nums[left] == target)
            return left;
        return -1;
    }
};