// 6024. 数组中紧跟 key 之后出现最频繁的数字
// https://leetcode-cn.com/contest/biweekly-contest-73/problems/most-frequent-number-following-key-in-an-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int mostFrequent(vector<int>& nums, int key) {
        // 遍历nums
        int target_count = 0; // 统计次数
        bool flag = true; // 标记key之后元素是否连续
        for (auto it = nums.begin(); it < nums.end(); it++) {
            if (*it == key) {

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
