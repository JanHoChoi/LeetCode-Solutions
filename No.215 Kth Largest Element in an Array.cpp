class Solution {
public:
    // 快排的想法, 最优情况下, 是 n + n/2 + n/4 ... = n
    int quickSortHelp(vector<int>& nums, int k, int start, int end){
        int n = end - start; // n表示的是数组一共有多少个数
        if(n==1)
            return nums[start];
        int left = start;
        int right = end-1;
        int index = nums[left];
        while(left < right){
            while(nums[right] >= index && right > left){
                right--;
            }
            nums[left] = nums[right];
            while(nums[left] <= index && left < right){
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = index;
        if(n - (left-start) == k) // n-(left-start)表示第x大
            return index;
        else if(n - (left-start) > k){
            return quickSortHelp(nums, k, left+1, end);
        }
        else{
            return quickSortHelp(nums, k-(n-(left-start)), start, left);
        }
    }

    // 建立一个容量为k的最小堆
    void min_heapify(vector<int> & nums, int start, int end){
        int father = start;
        int son = 2 * father + 1;
        while(son < end){
            if(son + 1 < end && nums[son] > nums[son+1])
                son++;
            if(nums[son] < nums[father]){
                swap(nums[son],nums[father]);
                father = son;
                son = 2 * father +1;
            }
            else
                return;
        }
        return;
    }

    int heapSortHelp(vector<int> & nums, int k){
        for(int i = k/2-1; i >= 0; i--){
            min_heapify(nums, i, k);
        }

        for(int i = k; i < nums.size(); i++){
            if(nums[i] < nums[0]){
                continue;
            }
            else{
                swap(nums[0],nums[i]);
                min_heapify(nums,0,k);
            }
        }
        return nums[0];

    }

    int findKthLargest(vector<int>& nums, int k) {
        return heapSortHelp(nums,k);
    }
};