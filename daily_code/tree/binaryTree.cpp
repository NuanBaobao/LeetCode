//
// Created by 张进华 on 2022/10/31.
//

//
// Created by 张进华 on 2022/10/29.
//

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 数组构造二叉树
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
void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << " " << root->val;
    preOrder(root->left);
    preOrder(root->right);
}

// 遍历二叉树
void traverseTree(TreeNode* root, int level){
    if(root == nullptr) return;
    cout << "Node " << root->val << " level = " << level << endl;
    traverseTree(root->left,level+1);
    traverseTree(root->right, level+1);
}
// 二叉树最大深度
int maxDepth(TreeNode* root){
    if(root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// 二叉树直径
void diameterOfTree(TreeNode* treeNode, int &maxDiameter){

}
// 统计二叉树节点个数
int countNode(TreeNode* root){
    if(root == nullptr) return 0;
    int leftNode = countNode(root->left);
    int rightNode = countNode(root->right);
    cout << "Node " << root->val << " leftChildren Size = " << leftNode << " rightChildren = " << rightNode << endl;
    return leftNode + rightNode + 1;
}

// 二叉排序树查找元素
TreeNode* findBST(TreeNode* root, int x){
    if(root == NULL) return NULL;
    if(root->val == x) {
        cout << "have found" << endl;
        return root;
    }
    if(root->val > x && root->left == NULL){
        root->left = new TreeNode(x);
        cout << "not find" << endl;
        return root;
    }
    if(root->val < x && root->right == NULL){
        root->right = new TreeNode(x);
        cout << "not find" << endl;
        return root;
    }
    if(root->val > x) return findBST(root->left,x);
    if(root->val < x) return findBST(root->right,x);
}

// 判断是否有子树
bool isSubTree(TreeNode* root, TreeNode* child){
    if(child == NULL) return true;
    if(root == NULL && child != NULL) return false;
    if(root->val == child->val){
        return isSubTree(root->left,child->left) && isSubTree(root->right,child->right);
    }
    return false;
}

bool judgeSimilaryTree(TreeNode* root, TreeNode* child){
    // 判断是否有child子节点
    if(child == NULL) return false;
    if(root == NULL && child != NULL) return false;
    bool flag = false;
    if(root->val == child->val){
        flag = isSubTree(root, child);
    }
    return flag || judgeSimilaryTree(root->left, child) || judgeSimilaryTree(root->right, child);
}

int main(void)
{
    int A[7] = {5,3,8,2,-1,7,9};
    TreeNode* root =  buildTree(A, 7);
    preOrder(root);
    cout << endl;
    int B[7] = {6,3,8,1,-1,7,9};
    TreeNode* child =  buildTree(B, 7);
    preOrder(child);
    cout << endl;
    cout << judgeSimilaryTree(root,child) << endl;
    return 0;
}