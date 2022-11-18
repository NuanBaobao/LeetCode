#include <iostream>
#include <vector>

using namespace std;

class NumArray {
   private:
    vector<int>& nums;
    vector<int> sum_nums;

   public:
    NumArray(vector<int>& nums) : nums(nums) {
        // 前缀数组
        vector<int> sum_nums(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                sum_nums[i] = nums[i];
            } else {
                sum_nums[i] = sum_nums[i - 1] + nums[i];
            }
        }
    }

    void update(int index, int val) {
        // 按索引修改
        int pre_val = nums[index]; // 修改前的值
        nums[index] = val;
        for(int i = index; i < sum_nums.size(); i++){
            sum_nums[i] = sum_nums[i] - val + pre_val;
        }
    }

    int sumRange(int left, int right) {
        return sum_nums[right] - sum_nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 */

int main(void)
{
    NumArray res;
    int num = {1,3,5};
    return 0;
}