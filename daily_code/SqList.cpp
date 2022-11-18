//
// Created by 张进华 on 2022/6/14.
//
# include<iostream>
using namespace std;

const int MaxSize = 10; // 顺序表的静态分配最大长度
const int InitSize = 15; // 顺序表的动态分配初始长度

// 顺序表静态分配的定义
//typedef struct {
//    int data[MaxSize]; // 顺序表元素
//    int length; // 顺序表的当前表长
//}SqList;

// 顺序表的动态分配定义
typedef struct {
    int *data; // 顺序表动态分配数组指针
    int max_length, length; // 顺序表的最大容量和当前元素个数
}SqList;

// 初始化表，构造空的线性表
bool InitSqList(SqList &L){
    // 动态分配
    L.data = new int[InitSize];
    for(int i = 0; i < 10; i++){
        // 初始化所有元素为0
        L.data[i] = i*i;
    }
    L.length = 10; // 初始化表长为1
    L.max_length = InitSize;
}

// 动态增加线性表长度
void IncreaseSqList(SqList &L, int len){
    int *p = L.data; // 暂存线性表元素
    L.data = new int[L.max_length + len];  // 新分配地址空间

    for(int i = 0; i < L.length; i++) L.data[i] = p[i]; // 复制

    L.max_length += len; // 修改容量

    cout << "increase successfully" << endl;
}

// 输出线性表元素
void PrintList(SqList L){
    if(L.length == 0){
        cout << "SqList is empty" << endl;
        return;
    }
    cout << "********************" << endl;
    cout << "SqList's length = " << L.length << endl;
    for(int i = 0; i < L.length; i++){
        cout << L.data[i] << " -> ";
    }
    cout << endl;
}

// 判断线性表是否为空
bool Empty(SqList L){
    if(L.length == 0){
        cout << "SqList is empty" << endl;
        return true;
    }
    return false;
}

// 销毁线性表
bool DestroyList(SqList &L){
    delete [] L.data;
}

// 求表长
int Length(SqList L){
    return L.length;
}

// 线性表的按值查找
int LocateElem(SqList L, int e){
    if(Empty(L)) return -1; // 线性表为空
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == e) return i+1; // 找到查找元素位序
    }
    return -1;
}

// 按位查找
int GetElem(SqList L, int i){
    if(Empty(L))
        return -1; // 线性表为空
    return L.data[i - 1];
}

// 线性表的插入
bool ListInsert(SqList &L, int i, int e){
    if(L.length >= L.max_length)  // 线性表已满
        return false;
    if(i < 1 || i > L.length + 1) // 插入位置不合法
        return false;
    for(int j = L.length;j >= i; j--){
        // 将第i个位置后的元素后移
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e; // 插入元素e
    L.length += 1; // 修改表长
    return true;
}

// 线性表的删除
bool ListDelete(SqList &L, int i, int &e){
    if(Empty(L)) return false; // 线性表为空
    if(i < 1 || i > L.length) return false; // 删除范围不合法

    e = L.data[i-1]; // 返回删除元素值
    for(int j = i; j < L.length; i++){
        L.data[i-1] = L.data[i]; // 元素前移
    }
    L.length -= 1; // 修改表长
    return true;
}

void reverse(SqList &L, int left, int right){
    while(left < right){
        int temp = L.data[left];
        L.data[left++] = L.data[right];
        L.data[right--] = temp;
    }
}
void reverse_A(SqList &L, int m, int n){
    int left = 0, right = m + n -1; // left指针子贤表头，right指向表尾
    reverse(L, 0, m+n-1);
    reverse(L, 0, n -1);
    reverse(L, n, m+n-1);
}

// 查找元素x在递增线性表中位置，将其与邻近元素交换位置，否则，将其插入并保持表依旧有序
void mid_search_exchange_insert(SqList &L, int x){
    int left = 0, right = L.length - 1, mid;
    while(left <= right){
        mid = (left + right) / 2; // 中间位置
        cout << "left = " << left << " mid = " << mid << " right = " << right << endl;
        if(L.data[mid] == x) break; // 找到该元素，退出循环
        if(L.data[mid] > x) right = mid - 1; // 到mid左半边查找
        else left = mid + 1; // mid右半边查找
    }

    if(L.data[mid] == x && mid != L.length - 1) {
        // 查找成功,且不在表尾时不用交换元素
        int temp = L.data[mid];
        L.data[mid] = L.data[mid+1];
        L.data[mid+1] = temp;
    }

    if(left > right){
        // 查找失败，将x插入表中
        if(L.length >= L.max_length){
            cout << "SqList is Full" << endl;
            return;
        }
        int i;
        for(i = L.length -1; i > right; i--){
            L.data[i+1] = L.data[i];
        }
        L.data[i+1] = x;
        L.length += 1;
    }
    return;

//    if(x > L.data[mid])
//        return mid_search(L, x, mid + 1, right); // 查找右边
//    else
//        return mid_search(L, x, left, mid - 1);
}
// 逆置辅助函数
void reverse_array(SqList &L, int start, int end){
    for(int i = 0; i < (end - start + 1) / 2; i++){
        swap(L.data[start+i], L.data[end-i]);
    }
}

// 算法思想:首先计算元素左移位数k = k % n(n为元素个数)，最多移动位数为表长,共左移K轮，每轮将元素左移一位
void left_move_k(SqList &L, int k){
    k = k % L.length; // 左移位数超过表长时减少移位
//    方法1 时间复杂度O(n**2)，空间复杂度O(1)
//    for(int i = 0; i < k; i++){
//        // 先保存队首元素
//        int prior_elm = L.data[0];
//        for(int j = 1; j < L.length; j++){
//            // 从第二个元素开始一次左移一位
//            L.data[(j -1 + L.length) % L.length] = L.data[j];
//        }
//        L.data[L.length-1] = prior_elm; // 表头元素移动到表尾
//    }
//算法思想:构造辅助数组B[k],暂存数组A前K个元素，然后将第k+1到n元素左移k位,最后将前B中元素依次插入数组A尾部
//    int B[k]; // 构造辅助数组
//    for(int i = 0; i < k; i++){
//        B[i] = L.data[i];
//    }
//    for(int i = k; i < L.length; i++){
//        // k-n-1左移K位
//        L.data[(i-k + L.length) % L.length] = L.data[i];
//    }
//    // B[0-k]加入A
//    for(int i = 0; i < k; i++){
//        L.data[L.length -k + i] = B[i];
//    }
//    算法思想:将问题等价为数组AB转变为BA(A代表前K个元素,B代表后n-k个元素),然后将A逆置得到A^-1B,再将B逆置得到A^-1B^-1,
//    最后整体逆置得到BA即为所求
    reverse_array(L, 0, k-1);
    reverse_array(L, k, L.length -1);
    reverse_array(L, 0, L.length - 1);
}

int main(void)
{
    SqList L1, L2; // 定义线性表
    InitSqList(L1);
    PrintList(L1);
//    mid_search_exchange_insert(L1, 10);
    left_move_k(L1, 20);
    PrintList(L1);
//    if(result == -1){
//
//    }
    return 0;
}
