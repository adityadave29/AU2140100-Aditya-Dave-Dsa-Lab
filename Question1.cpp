#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int srch(int x,int arr[],int n)
{
    for(int i=0;i<x;i++){
        if(arr[i]==n){
            return i+1;
        }
    }
    return -1;
}

int main()
{
    int n=5;
    int arr[] = {1,2,3,4,5};
    cout << srch(n,arr,11) << endl;
    cout << srch(n,arr,4) << endl;
}

// output:
// -1
// 4
