#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int h)
{
	int pivot = arr[h];
	int i = (l - 1);
	for (int j = l; j < h; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

void quickSort(int arr[], int l, int h)
{
	if (l < h)
	{
		int pi = partition(arr, l, h);
		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, h);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
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
	quickSort(arr, 0, n - 1);
	printArray(arr, n);
	return 0;
}
