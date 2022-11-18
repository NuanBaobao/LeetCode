//
// Created by 张进华 on 2022/10/29.
//

#include <iostream>
#include <queue>
using namespace std;

// 数组构造二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(int A[], int n) {
    TreeNode* root = new TreeNode(A[0]);
    int index = 0;
    queue<TreeNode*> que;
    que.push(root);
    while(index < n) {
        index++;
        if (index >= n) return root;
        TreeNode* node = que.front();
        que.pop();

        int leftChild = A[index];
        if (node != nullptr && leftChild != -1) {
            node->left = new TreeNode(leftChild);
            que.push(node->left);
        } else {
            que.push(nullptr);
        }
        index++;
        if (index >= n) return root;
        int rightChild = A[index];
        if (node != nullptr && rightChild != -1) {
            node->right = new TreeNode(rightChild);
            que.push(node->right);
        } else {
            que.push(nullptr);
        }
    }
    return root;
}

// 二叉树先序遍历
void preOrder(TreeNode* root, vector<int> &path) {
    if (root == nullptr) return;
    // cout << " " << root->val;
    path.push_back(root->val);
    preOrder(root->left, path);
    preOrder(root->right, path);
}


int main(void)
{
    int A[4] = {0,1,2,3};
    TreeNode* root =  buildTree(A, 4);
    vector<int> path;
    preOrder(root, path);
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    return 0;
}