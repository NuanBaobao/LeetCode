// 你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

// 假设你有 n 个版本 [1, 2, ...,
// n]，你想找出导致之后所有版本出错的第一个错误的版本。

// 你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version
// 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用
// API 的次数。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/first-bad-version
#include <iostream>
using namespace std;
int bad;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int testNumber) {
    if (testNumber == bad)
        return true;
    else
        return false;
}

class Solution {
   public:
    int firstBadVersion(int n) {
        // 二分查找边界
        int left = 1, right = n;
        while (left < right) {
            // int mid = (left + right) >> 1;
            int mid = left + (right - left) / 2; // 防止计算时溢出
            if (isBadVersion(mid)) {
                // 错误版本在前面, [left,right]
                right = mid;
            } else {
                // [mid+1,right]
                left = mid + 1;
            }
        }
        if (isBadVersion(left)) {
                return left;
            } else {
                return -1;
            }
    }
};

int main(void) {
    int n = 0;  // 产品个数
    cin >> n >> bad;

    Solution res;
    cout << res.firstBadVersion(n) << endl;
    return 0;
}