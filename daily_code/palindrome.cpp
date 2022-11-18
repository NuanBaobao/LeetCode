//
// Created by 张进华 on 2022/9/12.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string palindrome(string s, int l, int r){
        // 寻找以s[l]和s[r]为中心的最长回文串
        // 防止索引越界
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            // 双指针，向两边展开
            l--;
            r++;
        }
        // 返回以 s[l] 和 s[r] 为中心的最长回文串
        return s.substr(l+1, r-l-1);
    }
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++){
            //以s[i]为中心的最长回文子串
            string s1 = palindrome(s, i, i);
            // cout << "s1 " << s1 << endl;
            // 以 s[i] 和 s[i+1] 为中心的最长回文子串
            string s2 = palindrome(s, i, i + 1);
            // cout << "s2 " << s2 << endl;
            // res = longest(res, s1, s2)
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }
};

int main(void){
    string s = "abcdekgh";
    Solution res;

    cout << res.longestPalindrome(s) << endl;
}