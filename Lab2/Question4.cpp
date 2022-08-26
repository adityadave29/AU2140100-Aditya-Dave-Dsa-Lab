#include <bits/stdc++.h>
using namespace std;

int *insatend(int n,int arr[], int element)
{
    int i;
    n++;
    for (i = n; i >=n-1; i--)
        arr[i] = arr[i - 1];
    arr[n - 1] = element;

    return arr;
}

int main()
{
    int n,arr[100]={0};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    insatend(n,arr,3);
    for(int i = 0; i < n+1; i++){
        cout << arr[i] <<" ";
    }
}

// input:
// 4
// 1 2 3 4 
// output:
// 1 2 3 4 3