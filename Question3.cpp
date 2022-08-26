#include <bits/stdc++.h>
using namespace std;   

int deleteElement(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            break;
    if (i < n)
    {
        n = n - 1;
        for (int j = i; j < n; j++)
            arr[j] = arr[j + 1];
    }
    return n;
}

int main()
{
    int x,n,arr[100]={0};
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    n = deleteElement(arr, n, x);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

// input:
// 4 3
// 1 2 3 4        
// 1 2 4 