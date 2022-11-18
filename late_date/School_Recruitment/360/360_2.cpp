#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int n,m,t,x;
vector<int> A;
bool compare(int a,int b){
    return a > b;
}

void mySort(vector<int> &nums,int t,int x){
    if (t==0){
        sort(A.begin(),A.begin() + x);
    }else{
        sort(A.begin(),A.begin() + x,compare);
    }

    for(int i = 0;i < A.size();i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    cin >> n >> m;
    for(int i =0;i < n;i++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    for(int i = 0;i < m;i++){
        cin >> t >> x;
        mySort(A,t,x);
    }
    return 0;
}