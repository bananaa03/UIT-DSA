#include <iostream>
using namespace std;

void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int max = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] > a[max])
				max = j;
		swap(a[max], a[i]);
	}
}

// Ý tưởng: tìm phần tử lớn nhất, rồi đưa đến đầu mảng...