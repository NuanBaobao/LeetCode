//
// Created by 张进华 on 2022/8/19.
//

#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        // 指向三个有序链表头节点的指针
        int p2 = 1, p3 = 1, p5 = 1;
        // 三个有序链表头结点的值
        int p2_value = 1, p3_value = 1, p5_value =1;
        // 结果链表
        int *ugly = new int[n+1];
        // 结果链表指针
        int p = 1;

        // 合并有序链表
        while(p<=n){
            // 获取三个链表最小节点值
            int min_value = min(p2_value,min(p3_value,p5_value));
            // 加入结果链表
            ugly[p] = min_value;
            p++;
            // 前进对应有序链表指针
            if(min_value == p2_value){
                p2_value = 2 * ugly[p2];
                p2++;
            }
            if(min_value == p3_value){
                p3_value = 3 * ugly[p3];
                p3++;
            }
            if(min_value == p5_value){
                p5_value = 5 * ugly[p5];
                p5++;
            }
        }
        return ugly[n]; // 返回第n个丑数
    }
};

int main(void){
    Solution res;
    cout << res.nthUglyNumber(10) << endl;
    return 0;
}