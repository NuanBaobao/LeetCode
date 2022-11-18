# 算法入门
## 第一天 二分查找

### 二分查找解题流程模板如下：

- 整数二分查找情况一，如果我们要求的值尽量的靠近左边，套用模板如下：

  ```c++
  while(left < right){
      // int mid = left + right >> 1; // 利用位运算实现除法，可能会造成溢出
      int mid = left + (right - left) / 2; // 防止计算时溢出
      if(检查mid处值情况,满足条件){
          right = mid; // 区间[left,mid]
      }else{
          left = mid + 1; // 区间[mid+1,right]
      }
  }
  ```

- 整数二分查找情况二，如果我们要求的值尽可能靠近右边，套用模板如下：

  ```c++
  while(left < right){
      int mid = left + right + 1 >> 1;
      if(检查mid处值情况，满足条件){
          left = mid;
      }else{
          right = mid - 1;
      }
  }
  ```

- 浮点二分，套用模板如下：

  ```c++
  while(right > left + 1e-5){
      // 精度保证
      double mid = (left + right) / 2;
      if(检查mid处值情况，满足条件) right = mid;
      else left = mid;
  }
  ```

### 习题1 704.二分查找

- 链接：https://leetcode-cn.com/problems/binary-search

- 解题思路：套用模板1可直接解题

  ```c++
  class Solution {
     public:
      int search(vector<int> &nums, int target) {
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
  };
  ```
### 习题2 278.第一个错误的版本
- 链接：https://leetcode-cn.com/problems/first-bad-version/

- 解题思路：要求我们尽可能的减少调用检查函数的次数，也就是说最快找到第一个错误的版本，套用模板一

  ```c++
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
  ```
  
  ​	
