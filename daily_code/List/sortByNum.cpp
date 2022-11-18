#include<iostream>
using namespace std;

void sortByNum(int *A, int n){
    int pivot = A[0];
    int low = 0, high = n-1;
    while(low < high){
        while(A[high] % 2 == 0 && high > 0) high--;
        A[low] = A[high];
        while(A[low] % 2 != 0 && low < n) low++;
        A[high] = A[low];
    }
    A[low] = pivot;
}

int main(void)
{
    int A[8] = {8,7,6,5,4,3,2};
    sortByNum(A,7);
    for(int i = 0; i < 7; i++) cout << A[i] << " ";
    return 0;
}