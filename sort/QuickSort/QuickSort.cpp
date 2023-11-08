#include <iostream>
using namespace std;

void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2]; int l = left, r = right;
	while (l <= r)
	{
		while (a[l] > x) l++;
		while (x > a[r]) r--;
		if (l <= r)
		{
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	if (left > r)
		QuickSort(a, left, r);
	if (l > right)
		QuickSort(a, l, right);
}

//