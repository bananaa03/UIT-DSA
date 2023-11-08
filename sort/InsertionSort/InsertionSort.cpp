#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//Lưu giá trị để tránh bị ghi đè
		int element = a[i];
		//Vị trí chèn
		int j = i - 1;
		//Tìm vị trí chèn và dời chỗ các phần tử
		while (j >= 0 && a[j] < element)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = element;
	}
}

// Ý tưởng: Lưu giá trị lại -> chọn vị trí để chèn -> dời phần tử về phía sau (dời tới khi hết thỏa điều kiện) -> cho cái giá trị được lưu khi nãy thành vị trí mới (đúng chỗ)