#include <bits/stdc++.h>
using namespace std;

int *insatbeg(int n,int arr[], int element)
{
    int i;
    n++;
    for (i = n; i>=0; i--)
        arr[i] = arr[i - 1];
    arr[0] = element;

    return arr;
}

int main()
{
    int n,arr[100]={0};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    insatbeg(n,arr,3);
    for(int i = 0; i < n+1; i++){
        cout << arr[i] <<" ";
    }
}

// input:
// 4
// 1 2 3 4
// output:
// 3 1 2 3 4 
