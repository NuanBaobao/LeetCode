// 388. 文件的最长绝对路径
// https://leetcode-cn.com/problems/longest-absolute-file-path/

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        // 统计当前文件的层数
        int input_length = input.size();
        int pos = 0; // 记录遍历到的字符位置

        vector<int> level(input_length+1);
        while(pos < input_length){
            int depth = 1;
            // 计算文件所处层数
            while(pos < input_length && input[pos] == '\t'){
                pos++;
                depth++;
            }
            // 计算文件长度
            int len = 0;
            bool is_file = false; // 标记是否为文件
            while(pos < input_length && input[pos] != '\n'){
                if(input[pos] == '.'){
                    is_file = true;
                }
                pos++;
                len++;
            }
            pos++;

            if(depth > 1){
                len = level[depth-1] + 1; // 更新
            }

            if(is_file){
                res = max(res, len);
            }
            else{
                level[depth] = len;
            }
        }
        return res;
    }
};

int main(void)
{
    string file_system;
    cin >> file_system;

    Solution res;
    cout << res.lengthLongestPath(file_system) << endl;
    return 0;
}