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

ListNode* tailInsert(){
    int n = 7;
    int A[8] = {1,3,3,4,6,6,8};
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

int main(void)
{
    ListNode* L = tailInsert();
    printList(L);
    ListMatrix* res = new ListMatrix();
    res = solve(L);

    
    return 0;
}