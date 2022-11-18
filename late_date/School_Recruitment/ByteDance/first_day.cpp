//
// Created by 张进华 on 2022/3/17.
//
//用户喜爱度
# include<iostream>
# include<vector>
# include <map>

using namespace std;

class Solution {
public:
    int countNumber(vector<int> &nums, int left, int right, int target) {
//        left 左边界 right 右边界 target 目标值
        // 遍历查找
        int res = 0; // 统计结果
        while (left < right) {
            if (nums[left - 1] == target) {
                // 与目标值相同
                res++;
                left++;
            } else {
                left++;
            }
        }
        return res;
    }

//    int countIllegal(){
//
//    }
};


int main(void) {
//    用户喜爱度

    int n;
    vector<int> input_vector;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        input_vector.push_back(x);
    }
    Solution res;
    int q, l, r, k;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> k;
        cout << res.countNumber(input_vector, l, r, k) << endl;
    }
    return 0;

//    int n, m, c;
//    cin >> n >> m >> c;
//    for (int i = 0; i < n; i++) {
//        int num_i;
//        cin >> num_i;
//        for(int j = 0; j < num_i; j++){
//            int color;
//            cin >> color;
//            if(color)
//        }
//    }

}