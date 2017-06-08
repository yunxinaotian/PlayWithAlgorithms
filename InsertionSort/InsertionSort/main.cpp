#include<iostream>
#include<algorithm>
#include"SelectionSort.h"
#include"SortTestHelper.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		//寻找元素arr[i]合适的插入位置
		T e = arr[i];
		int j;//保存元素e应该插入的位置
		for (j = i; j > 0 && arr[j-1] > e; j--){
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
}

int main() {

	int n = 10000;
	//int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);


	delete[] arr;
	delete[] arr2;

	system("pause");
	return 0;
}