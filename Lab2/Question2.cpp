#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int* insatind(int n,int arr[],int pos,int element)
{
    int i;
	n++;
	for (i = n; i >= pos; i--)
		arr[i] = arr[i - 1];
	arr[pos - 1] = element;

	return arr;
}

int main()
{
    int n,arr[100]={0};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    insatind(n,arr,3,4);
    for(int i = 0; i < n+1; i++){
        cout << arr[i] <<" ";
    }
}


// input : 
// 3
// 1 2 3
// output:
// 1 2 4 3