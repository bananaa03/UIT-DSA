#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i; // Kh?i t?o largest l� v? tr� c?a node cha
	int left = 2 * i + 1; // V? tr� con tr�i
	int right = 2 * i + 2; // V? tr� con ph?i

	// N?u t?n t?i con tr�i l?n h?n cha
	if (left < n && arr[left] > arr[largest])
		largest = left;

	// N?u t?n t?i con ph?i l?n h?n arr[max]
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// N?u node cha kh�ng ph?i l?n nh?t
	if (largest != i) {       
		// ??i ch? cho ph?n t? l?n nh?t l�m cha
		swap(arr[i], arr[largest]); 

		// ?? quy vun ??ng c�c node ph�a d??i
		heapify(arr, n, largest);   
	}
}

void heapSort(int arr[], int n)
{
	// X�y d?ng heap (s?p x?p l?i m?ng)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		// Ho�n v? node g?c v?i node l� cu?i c�ng
		swap(arr[0], arr[i]);

		// T�i t?o l?i c?u tr�c heap
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
	return 0;
}
