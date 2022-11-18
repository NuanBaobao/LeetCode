#include<iostream>
using namespace std;

int binarySearch(int A[], int x, int n){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        cout << " " << A[mid];
        if(A[mid] == x) return mid;
        if(A[mid] > x){
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(void)
{
    int A[13] = {2,10,25,35,40,65,70,75,81,82,88,100};
    int index = binarySearch(A,75,12);
    cout << endl;

    cout << index << endl;
    return 0;
}