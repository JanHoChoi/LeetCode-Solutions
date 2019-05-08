class Solution {
public:
    // O(nlogn) 二分搜索 因为数字范围是1~n(数组有n+1个数)，所以取(1+n+1)/2，再遍历数组，看看有多少个数<=mid
    // 理论上如果没有重复，则应该刚好有 1.2.3...mid个数<=mid，若小于这个值，则证明大数多余 否则 小数多余
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size();
        while(left != right){
            int mid = (left+right)/2;
            int count = 0;
            for(auto i : nums){
                if(i <= mid)
                    count++;
            }
            if(count <= mid)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    // O(n) 快慢指针
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]]; // 快指针走两步
            if(fast == slow)
                break;
        }
        int start = nums[0];
        while(start != fast){
            start = nums[start];
            fast = nums[fast]; // 从相遇点开始一步一步走
        }
        return start;
    }
};