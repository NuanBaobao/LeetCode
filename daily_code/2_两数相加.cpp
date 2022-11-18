//
// Created by 张进华 on 2022/7/14.
//

//
// Created by 张进华 on 2022/7/5.
//

# include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef string ElemType;

// 单链表节点
struct ListNode{
    ElemType data; //数据域
    ListNode *next; // 指针域
    ListNode() : data(), next(NULL) {}
    ListNode(ElemType x) : data(x), next(NULL) {}
    ListNode(ElemType x, ListNode *next) : data(x), next(next) {}
};

int Length(ListNode* L){
    // 单链表表长
    int length = 0;
    ListNode *p = L;
    while(p != NULL){
        length++;
        p = p->next;
    }
    return length;
}

// // 合并两个升序链表
// ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//     ListNode *dummy = new ListNode(0), *p = dummy;
//     ListNode *p1 = list1, *p2 = list2;
//     while(p1 != NULL && p2 != NULL){

//     }
// }

// 头插法建立单链表(不带头节点）
void ListHeadInsert(ListNode* &L){
    L = NULL;

    int n = 0; // 表长
    cout << "please input the length of ListNode" << endl;
    cin >> n;

    ElemType x;

    cout << "please input the data" << endl;
    for(int i = 0; i < n; i++){
        cin >> x;
        ListNode *s = new ListNode(x, L);
        // s -> data = x;
        // s->next = L;
        L = s;
    }
}

// 尾插法
void ListTailInsert(ListNode* &L){
    L = new ListNode();
    L = NULL;
    ListNode *r = L; // 尾节点
    int n = 0;
    cout << "please input the length of ListNode" << endl;
    cin >> n;
    cout << "please input the data" << endl;

    ElemType x;
    for(int i = 0; i < n; i++){
        cin >> x;
        ListNode *s = new ListNode(x);
        if(L == NULL){
            L = s;
            r = L;
        }
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

// 按序号查找
ListNode *GetElem(ListNode* &L, int i){
    int j = 0; // 计数
    ListNode *p = L; // 工作指针
    if(i == 0) return L; // i=0, 返回头节点
    if(i < 1) return NULL; // 查找无效
    while(p != NULL && j < i){ // 从第头节点开始查
        p = p->next;
        j++;
    }
    return p; // 返回第i个节点指针
}

// 按值查找
int LocateElem(ListNode* &L, ElemType x){
    ListNode *p = L; // 从第一个节点开始查找
    int pos = 1; // 记录位置
    while(p != NULL && p->data != x){
        p = p->next;
        pos++;
    }
    if(p != NULL)
        return pos; // 返回结点指针，失败返回NULL
    return -1;
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


// 反转链表
ListNode* ReverseList(ListNode* &head){
    ListNode *dummy = new ListNode();
    ListNode *s = head, *r;

    while(s != NULL){
        r = s->next;
        s->next = dummy->next;
        dummy->next = s;
        s = r;
    }
    return dummy->next;
}


// 链表后半段逆置
ListNode* reverse_right_list(ListNode* head){
    // 快慢指针
    ListNode *p, *q, *r, *s;
    p = head, q = head; // 快慢指针找中间节点
    while(q != NULL && q->next != NULL){
        p = p->next;
        q = q->next->next;
    }
    q = p->next; // q为后半段首节点
    p->next = NULL; // p为中间节点

    while(q != NULL){
        // 链表后半段逆置
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }

    s = head; // s指向前半段第一个数据节点
    q = p->next; // q指向后半段第一个数据节点
    cout << s->data << " " << p->data << " " << q->data << endl;
    return head;
}

// 链表前半段逆置
ListNode* reverse_left_list(ListNode* head){
    ListNode *p, *q, *r, *s;
    p = head, q = head; // 快慢指针找中间节点
    ListNode* dummy = new ListNode(); // 虚拟头节点
    while(q->next != NULL){
        p = p->next;
        q = q->next;
        if(q->next != NULL){
            q = q->next;
        }
    }
    q = p->next; // q指向后半段第一个数据节点

    s = head; // s指向前半段第一个数据节点
    dummy->next = p;
    while(s != p){
        // 链表前半段逆置
        r = s->next;
        s->next = dummy->next;
        dummy->next = s;
        s = r;
    }
    s = dummy->next; // s指向前半段第一个数据节点
    return dummy->next;

    cout << s->data << " " << p->data << " " << q->data << endl;
}


// 递归反转单链表
ListNode* reverse(ListNode* head){
    // 将以head开头的链表进行反转，并返回反转后链表的首节点(head是第一个存数据节点，不是头节点)
    if(head == NULL or head->next == NULL) // 链表为空或者只有一个节点
        return head;
    ListNode *last = reverse(head->next);
    head->next->next = head; // head与其后继节点建立方向关系
    head->next = NULL; // head为尾节点
    return last;
}


ListNode* reverseN(ListNode* head, int n, ListNode* &successor){
    if(n == 1){
        successor = head->next; // 记录第n+1个节点
        return head;
    }
    // 以head.next为起点，反转前n-1个节点
    ListNode* last = reverseN(head->next, n-1,successor);

    head->next->next = head;
    head->next = successor; // 反转后的head节点与后面的节点连接起来
    return last;
}

ListNode* reverse_between(ListNode* head, int m, int n, ListNode* &successor){
    if(m == 1){
        return reverseN(head, n, successor);
    }
    head->next = reverse_between(head->next, m-1, n-1,successor);
    return head;
}



int main(void)
{
    ListNode* L1,L2;
    // 插入法建立单链表
    ListTailInsert(L1);
    printLNode(L1);

    L1 = reverse_left_list(L1);
    printLNode(L1);
    // L1 = reverse_left_list(L1);
    // printLNode(L1);

    return 0;
}
