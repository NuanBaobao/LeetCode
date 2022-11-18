//
// Created by 张进华 on 2022/8/23.
//
// 逆序打印单链表
#include <iostream>

using namespace std;

typedef int ElemType;

// 单链表节点
struct ListNode{
    ElemType data; //数据域
    ListNode *next; // 指针域
    ListNode() : data(), next(NULL) {}
    ListNode(ElemType x) : data(x), next(NULL) {}
    ListNode(ElemType x, ListNode *next) : data(x), next(next) {}
};

// 链表长度(不带头结点）
int getLength(ListNode* &head){
    int length = 0;
    ListNode *p = head;
    while(p != NULL){
        length++;
        p = p->next;
    }
    return length;
}

// 尾插法
void ListTailInsert(ListNode* &head, int n){
    head = new ListNode();
    head = NULL;
    ListNode *r = head; // 尾节点
    ElemType x;
    for(int i = 0; i < n; i++){
        cin >> x;
        ListNode *s = new ListNode(x);
        if(head == NULL){
            head = s;
            r = head;
        }
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

// 输出链表内容(不带头结点）
void printLNode(ListNode* &head){
    ListNode *p = head;
    while(p != NULL){
        cout << " " << p->data;
        p = p->next;
    }
    cout << endl;
    return;
}



class Solution{
public:
//    递归遍历单链表，倒序打印链表元素
    void traverse(ListNode* head){
        if(head == NULL) return;
        traverse(head->next);
        cout << head->data << " ";
    }
};

int main(void)
{
    Solution res;
    ListNode *head;
    ListTailInsert(head, 5);
    printLNode(head);
    res.traverse(head);
    printLNode(head);
    res.traverse(head);
    printLNode(head);
    return 0;
}