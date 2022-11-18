// 388. 文件的最长绝对路径
// https://leetcode-cn.com/problems/longest-absolute-file-path/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // 深度优先搜索
        if(p == nullptr && q == nullptr){
            // 两棵树都为空
            return true;
        }
        else if(p == nullptr || q == nullptr){
            // 仅有一棵树为空
            return false;
        }
        else{
            // 判断两颗子树是否相同
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }   
    }
};

int main(void) {
    Solution res;

    return 0;
}