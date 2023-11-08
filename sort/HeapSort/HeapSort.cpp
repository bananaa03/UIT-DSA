#include <iostream>
using namespace std;

void Heapify(int a[], int n, int i)
{
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] < a[smallest])
		smallest = l;
	if (r < n && a[r] < a[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(a[i], a[smallest]);
		Heapify(a, n, smallest);
	}
}

void HeapSort(int a[], int n)
{
	for (int i = n / 2 + 1; i >= 0; i--)
		Heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		Heapify(a, 0, i);
	}
}