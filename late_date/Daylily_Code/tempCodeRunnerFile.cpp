class Solution {
   public:
    int search(vector<int>& nums, int target) {
        // 定义左右边界
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + right >> 1;
            // 满足两指针未相遇时搜索
            if (nums[mid] >= target) {
                // 如果中间值大于目标值，则在左半边查找
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (nums[left] != target) {
            return -1;
        } else {
            return left;
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        // 定义初始左右边界
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >> target) {
                // 如果中间值大于目标值，则在左区间
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (nums[left] == target) {
            // 找到目标值
            return left;
        } else if (nums[left] < target) {
            // 插入到右边
            return left + 1;
        } else {
            if (nums.size() == 1) {
                // 仅有一个元素
                return left;
            } else {
                // 插入左边
                return left - 1;
            }
        }
    }
};