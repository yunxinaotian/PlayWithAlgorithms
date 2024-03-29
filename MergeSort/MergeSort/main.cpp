#include <iostream>
#include<algorithm>
#include"SortTestHelper.h"
#include"InsertionSort.h"

using namespace std;

//将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {

	int *aux = new int[r - l + 1];
	//T aux[r - l + 1];
	for (int i = l; i <= r; i++) {
		aux[i-l] = arr[i];
	}
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k ++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j ++;
		}
		else if( j > r ) {
			arr[k] = aux[i - l];
			i ++;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k] = aux[i - l];
			i ++;
		}
		else {
			arr[k] = aux[j - l];
			j ++;
		}
	}

}


//递归使用归并排序，对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {

	//if (l >= r)
	//	return;
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if( arr[mid] > arr[mid+1] )
		__merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
	
	__mergeSort( arr , 0, n-1);
}

int main() {

	int n = 50000;
	cout << "Test for Random  Array, size = " << n << ", ranom range[0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	int swapTimes = 10;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete(arr1);
	delete(arr2);

	system("pause");
	return 0;
}