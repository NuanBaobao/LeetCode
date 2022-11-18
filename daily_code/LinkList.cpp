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
};

int Length(ListNode* L){
    // 单链表表长
    int length = 0;
    ListNode *p = L->next;
    while(p != NULL){
        length++;
        p = p->next;
    }
    return length;
}
// 头插法建立单链表(不带头节点）
void ListHeadInsert(ListNode* &L){
    L = NULL;

    int n = 0; // 表长
    cout << "please input the length of ListNode*" << endl;
    cin >> n;

    ElemType x;
    ListNode *s;
    cout << "please input the data" << endl;
    for(int i = 0; i < n; i++){
        cin >> x;
        s = new ListNode;
        s -> data = x;

        s->next = L;
        L = s;
    }
}

// 尾插法
void ListTailInsert(ListNode* &L){
    L = new ListNode;
    L->next = NULL;
    ListNode *r = L; // 尾节点
    int n = 0;
    cout << "please input the length of ListNode*" << endl;
    cin >> n;
    cout << "please input the data" << endl;

    ElemType x;
    for(int i = 0; i < n; i++){
        cin >> x;
        ListNode *s = new ListNode;
        s->data = x;
        s->next = r->next;
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
    ListNode *p = L->next; // 从第一个节点开始查找
    int pos = 1; // 记录位置
    while(p != NULL && p->data != x){
        p = p->next;
        pos++;
    }
    if(p != NULL)
        return pos; // 返回结点指针，失败返回NULL
    return -1;
}

// 输出链表内容(带头结点）
void printLNode(ListNode* &L){
    ListNode *p = L->next;
    while(p != NULL){
        cout << " " << p->data;
        p = p->next;
    }
    cout << endl;
    return;
}

// 输出链表内容(不带头结点）
void printLNode2(ListNode* &L){
    ListNode *p = L;
    while(p != NULL){
        cout << " " << p->data;
        p = p->next;
    }
    cout << endl;
    return;
}

// 插入元素(后插)
//bool ListInsert(ListNode* &L, int pos, ElemType e){
//    if(pos < 1 || pos > L->data + 1) return false; // 插入失败
//    // 插入节点的前驱
//    ListNode *p = GetElem(L, pos-1);
//
//    ListNode *s = new ListNode; // 插入节点
//    s->data = e;
//    s->next = p->next;
//    p->next = s;
//
//    L->data += 1; // 修改表长
//
//    return true;
//}

//bool ListDelete(ListNode* &L, int pos, ElemType &e){
//    if(pos < 1 || pos > L->data) return false; // 删除失败
//    // 删除节点前驱
//    ListNode *p = GetElem(L, pos-1);
//    ListNode *q = p->next;
//    e = q->data; // 返回删除值
//    p->next = q->next;
//    L->data -= 1;
//    return true;
//}

void ChangeList(ListNode* &L){
    ListNode *p, *q, *r, *s;
    p = L, q = L; // 快慢指针找中间节点
    while(q->next != NULL){
        p = p->next;
        q = q->next;
        if(q->next != NULL) q = q->next;
    }
//    cout << p->data << " " << q->data << endl;
    q = p->next; // p为中间节点，q为后半段首节点
    p->next = NULL;

    while(q != NULL){
        // 链表后半段逆置
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = L->next; // s指向前半段第一个数据节点：插入点
    q = p->next; // q指向后半段第一个数据节点
    while(q != NULL){
        // 将后半段数据节点插入
        r = q->next;
        p->next = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
}

// 反转链表
void ReverseList(ListNode* &L){
    ListNode *s = L->next, *r;
    L->next = NULL;
    while(s != NULL){
        r = s->next;
        s->next = L->next;
        L->next = s;
        s = r;
    }
}

//// 去除链表重复元素
//void RemoveElm(ListNode* &L, int m){
//    // 辅助数组记录重复元素
//    int * pos = new int [m+1];
//    for(int i = 0; i <= m; i++) {
//        pos[i] = 0;
//    }
//
//    // 遍历单链表
//    ListNode *p = L, *q = L->next, *r; // q为工作指针，指向删除元素，p为q前驱
//    while(q != NULL){
//        if(pos[abs(q->data)] == 1){
//            // 重复元素
//            p->next = q->next;
//            q = q->next;
////            L->data--;
//        } else{
//            pos[abs(q->data)] = 1; // 存在过
//            p = p->next;
//            q = q->next;
//        }
//    }
//}

//// 单词相同后缀
//ListNode * SameSuffix(ListNode* &L1, ListNode* &L2){
//    // 双指针
//    ListNode *p = L1->next;
//    ListNode *q = L2->next;
//    // 表长
//    int m = L1->data;
//    int n = L2->data;
//    // 对齐
//    if(m > n){
//        for(int i = m;i > n;i--){
//            // 若m>n，p指向第n-m+1个节点
//            p = p->next;
//        }
//    }
//    if(m < n){
//        for(int i = n;i > m;i--){
//            // 若m>n，p指向第n-m+1个节点
//            q = q->next;
//        }
//    }
//    while (p->next != NULL && p->next != q->next){
//        p = p->next;
//        q = q->next;
//    }
//    return p->next;
//}

// 链表后半段逆置
bool reverse_right_list(ListNode* &L){
    ListNode *p, *q, *r, *s;
    p = L, q = L; // 快慢指针找中间节点
    while(q->next != NULL){
        p = p->next;
        q = q->next;
        if(q->next != NULL){
            q = q->next;
        }
    }
    q = p->next; // q为后半段首节点
    p->next = NULL; // q为中间节点

    while(q != NULL){
        // 链表后半段逆置
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }

    s = L->next; // s指向前半段第一个数据节点
    q = p->next; // q指向后半段第一个数据节点
}

// 链表前半段逆置
bool reverse_left_list(ListNode* &L){
    ListNode *p, *q, *r, *s;
    p = L, q = L; // 快慢指针找中间节点
    while(q->next != NULL){
        p = p->next;
        q = q->next;
        if(q->next != NULL){
            q = q->next;
        }
    }
    q = p->next; // q指向后半段第一个数据节点

    s = L->next; // s指向前半段第一个数据节点
    L->next = p;
    while(s != p){
        // 链表后半段逆置
        r = s->next;
        s->next = L->next;
        L->next = s;
        s = r;
    }
    s = L->next; // s指向前半段第一个数据节点

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


bool reverse_list_recursion(ListNode* &L){
    ListNode *s = L->next; // 记录头节点
    ListNode *new_head = reverse(s); // 反转
    L->next = new_head;
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

bool reverseN_list_recursion(ListNode* &L, int n){
    // 递归反转链表前n个元素(头节点不计数)
    ListNode *successor = NULL; // 记录后继节点
    ListNode *s = L->next; // 记录头节点
    ListNode *new_head = reverseN(s, n, successor); // 反转前n个元素
    L->next = new_head;
}

ListNode* reverse_between(ListNode* head, int m, int n, ListNode* &successor){
    if(m == 1){
        return reverseN(head, n, successor);
    }
    head->next = reverse_between(head->next, m-1, n-1,successor);
    return head;
}

bool reverse_between_recursion(ListNode* &L, int m, int n){
    // 反转链表m-n内容
    ListNode *successor = NULL; // 记录后继节点
    ListNode *s = L->next;
    ListNode *new_head = reverse_between(s, m, n, successor);
    L->next = new_head;
}

// 判断是否为中心对称单链表
bool central_list(ListNode* &L){
    reverseN_list_recursion(L, int(Length(L) / 2));
    printLNode(L);
    ListNode *p, *q, *r, *s;
    p = L, q = L; // 快慢指针找中间节点
    while(q->next != NULL){
        p = p->next;
        q = q->next;
        if(q->next != NULL){
            q = q->next;
        }
    }
    q = p->next; // q指向后半段第一个数据节点
    s = L->next; // s指向前半段第一个数据节点

//    cout << s->data << " " << p->data << " " << q->data << endl;

    while(s != p){
        // 前后端依次比较
        if(s->data == q->data){
            s = s->next;
            q = q->next;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(void)
{
    ListNode* L1,L2;
    // 插入法建立单链表
    ListTailInsert(L1);
    printLNode2(L1);

    cout << central_list(L1) << endl;
    return 0;
}