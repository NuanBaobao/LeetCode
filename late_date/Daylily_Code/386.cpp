// 386. 字典序排数
// https://leetcode-cn.com/problems/lexicographical-numbers/

#include <iostream>
#include<cmath>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
    //     // 一位数
    //     if (n < 10) {
    //         for (int i = 1; i <= n; i++) {
    //             res.push_back(i);
    //         }
    //         return res;
    //     }
    //     // 两位数
    //     else if (n < 100) {
    //         int first_num = n / 10;
    //         for (int i = 1; i <= 9; i++) {
    //             res.push_back(i);
    //             int temp = i * 10;
    //             while(temp < (i + 1) * 10 && temp <= n){
    //                 res.push_back(temp);
    //                 temp++;
    //             }
    //         }
    //     }
    int num = 1;
    for(int i = 0; i < n; i++){
        res.push_back(num);
        if(num * 10 <= n){
            num *= 10;
        }
        else{
            // 字典序开头加一
            while(num % 10 == 9 || num + 1 > n){
                num = int(num / 10);
            }
            num += 1;
        }
    }
    return res;
    }
};

int main(void) {
    int n;

    cin >> n;

    vector<int> result;

    Solution res;
    result = res.lexicalOrder(n);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    
    return 0;
}
