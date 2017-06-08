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
