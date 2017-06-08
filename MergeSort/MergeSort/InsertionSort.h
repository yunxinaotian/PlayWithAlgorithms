#pragma once
#include <iostream>
#include <algorithm>

using namespace std;


template<typename T>
void insertionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		T e = arr[i];
		int j;//����Ԫ��eӦ�ò����λ��
		for (j = i; j > 0 && arr[j - 1] > e; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
}

template<typename T>
void insertionSort(T arr[], int l, int r) {
	for (int i = l + 1; i <= r; i++) {

		T e = arr[i];
		int j;
		for (j = i; j > l && arr[j - 1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
	return;
}