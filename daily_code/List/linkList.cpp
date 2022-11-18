#include<iostream>
#include<stack>
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
struct ListMatrix {
    ListNode* list;
    ListMatrix *next;
};

void pushPack(ListNode* head, int x){
    // ListNode *rear = head;
    // while(rear != NULL){
    //     rear = rear->next;
    // }
    ListNode* node = new ListNode(x);
    // rear->next = node;
    node->next = head->next;
    head->next = node;
}

ListMatrix* solve(ListNode* list){
    ListMatrix* head = new ListMatrix();
    ListMatrix* ans = head;
    head->list = new ListNode();
    ListNode* p = list->next;

    int preVal = p->data - 1;
    while(p != NULL){
        if(p->data != preVal){
            ans = head;
            cout << ans->list->data;
            pushPack(ans->list, p->data);
            preVal = p->data;
        }else{
            if(ans->next == NULL){
                ans->next = new ListMatrix();
            }
            ans = ans->next;
            pushPack(ans->list,p->data);
        }
        p = p->next;
    }
    return head;
}

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

ListNode* tailInsert(int n, int *A){
    ListNode* L = new ListNode(), *rear = L;
    for(int i = 0;i < n; i++){
        ListNode *p = new ListNode(A[i]);
        rear->next = p;
        rear = p;
        p->next = NULL;
    }
    return L;
}

void printList(ListNode* head){
    if(head->next == NULL) cout << "empty list!" << endl;
    ListNode* p = head->next;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 链表的拆分
ListNode* ListSplit(ListNode*& L, bool &flag){
    if(L == NULL) return NULL;
    ListNode *slow = L, *fast = L->next;
    ListNode *dummy = new ListNode(), *rear = dummy;
    while(fast != NULL){
        if(fast->data != slow->data){
            slow->next = fast;
            slow = slow->next;
            fast = fast->next;
        }else{
            flag = true;
            ListNode* s = fast;
            fast = fast->next;
            s->next = NULL;
            rear->next = s;
            rear = s;
        }
    }
    return dummy;
}

// 升序链表合并并输出
ListNode* mergeList(ListNode* headA, ListNode* headB){
    ListNode *p1 = headA->next, *p2 = headB->next;
    ListNode* dummy = new ListNode();
    while(p1 != nullptr && p2 != nullptr){
        if(p1->data > p2->data){
            ListNode* s = new ListNode(p2->data);
            s->next = dummy->next;
            dummy->next = s;
            p2 = p2->next;
        }else{
            ListNode* s = new ListNode(p1->data);
            s->next = dummy->next;
            dummy->next = s;
            p1 = p1->next;
        }
    }
    if(p1 != nullptr){
        ListNode* s = new ListNode(p1->data);
            s->next = dummy->next;
            dummy->next = s;
            p1 = p1->next;
    }else{
        ListNode* s = new ListNode(p2->data);
        s->next = dummy->next;
        dummy->next = s;
        p2 = p2->next;
    }
    return dummy;
}

int main(void)
{
    int A[5] = {1,5,7,10};
    int B[7] = {2,4,6,9,19,56};
    ListNode* L1 = tailInsert(4,A);
    printList(L1);
    ListNode* L2 = tailInsert(6,B);
    printList(L2);
    ListNode* res = mergeList(L1,L2);
    printList(res);  
    return 0;
}