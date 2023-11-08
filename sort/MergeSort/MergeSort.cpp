#include <iostream>
using namespace std;

void Merge(int a[], int low, int mid, int high)
{
	int n = high - low + 1;
	int* b = new int[n];
	int left = low, right = mid + 1, idx = 0;
	while (left <= mid && right <= high)
		b[idx++] = (a[left] >= a[right]) ? a[left++] : a[right++];
	while (left <= mid) b[idx++] = a[right++];
	for (int k = 0; k < n; k++)
		a[low + k] = b[k];
	delete[]b;
}

void MergeSort(int a[], int low, int high)
{
	if (low < high) {
		int mid = (low + high) / 2;;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		Merge(a, low, mid, high);
	}
}

//Cần xem lại