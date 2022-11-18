// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target
//  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binary-search

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        // 定义左右边界
        int left = 0, right = nums.size() - 1;

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

    int searchInsert(vector<int> &nums, int target) {
        // 定义初始左右边界
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) {
                // 如果中间值大于目标值，则在左区间
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (nums[left] >= target) {
            // 找到目标值或插入左边
            return left;
        } else {
            // 插入到右边
            return left + 1;
        }
    }
};

int main() {
    int n, target;  // 有序数组容量及目标值
    vector<int> input_vector;
    cin >> n >> target;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        input_vector.push_back(x);
    }
    Solution res;
    cout << res.searchInsert(input_vector, target) << endl;

    return 0;
}
