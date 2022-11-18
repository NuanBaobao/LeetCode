#include<iostream>
using namespace std;

int getMax(int A[], int n){
    int temp = -9999;
    for(int i = 0; i < n; i++){
        for(int j = i+1;j < n;j++){
            if(A[i] - A[j] > temp){
                temp = A[i] - A[j];
            }
        }
    }
    return temp;
}

int main(void)
{
    int A[10] = {1,2,5,9,4,3,-2,90,100};
    cout << getMax(A,9) << endl;
    return 0;
}