// import java.util.*;
#include <bits/stdc++.h>
using namespace std;
// USING BINARY SEARCH:-

int binarySearch(int arr[], int target, int j)
{
    int low = 0;
    int high = j;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    int i = 1;
    while (i < n)
    {
        key = arr[i];
        int j = i - 1;
        if (arr[j] > key)
        {
            int loc = binarySearch(arr, key, j);
            while (j >= loc)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        else
        {
            i++;
        }
    }
    for (int z = 0; z < n; z++)
    {
        cout << arr[z] << " ";
    }
}
