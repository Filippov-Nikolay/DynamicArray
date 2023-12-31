﻿#include "DynamicArray.h"
#include <Windows.h>

DynamicArray::DynamicArray():ptr(nullptr),size(0) {}
DynamicArray::DynamicArray(int S) {
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S];	
}
// copy constructor
DynamicArray::DynamicArray(const DynamicArray &a) {
	cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray::~DynamicArray() {
	cout << "Destruct\n";
	if (ptr != 0)
	{
		delete[] ptr;
    }
	Sleep(1000);
}

void DynamicArray::Input() {
	for (int i = 0; i < size; i++)
		ptr[i] = rand() % 20;
	
}
void DynamicArray::Output() const {
	for (int i = 0; i < size; i++)
		cout<<ptr[i] <<"\t";
	
	cout << "\n---------------------------------\n";
}
int* DynamicArray::GetPointer() const {
	return ptr;
}
int DynamicArray::GetSize() const {
	return size;
}

void DynamicArray::ReSize(int newSize) {
	int tempSize = size;
	size += newSize;
	
	int* newPtr = new int[size];

	for (int i = 0; i < tempSize; i++)
		newPtr[i] = ptr[i];

	for (int i = tempSize; i < size; i++)
		newPtr[i] = 0;

	delete[] ptr;

	ptr = newPtr;
}
void DynamicArray::Sort() {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (ptr[j] > ptr[j + 1]) {
				int temp = ptr[j];
				ptr[j + 1] = ptr[j];
				ptr[j + 1] = temp;
			}
		}		
	}
}
int DynamicArray::Search(int key) const {
	for (int i = 0; i < size; i++)
		if (ptr[i] == key)
			return i;
	return -1;
}
void DynamicArray::Reverse() {
	for (int i = 0; i < size / 2; i++) {
		int temp = ptr[i];
		ptr[i] = ptr[size - 1 - i];
		ptr[size - 1 - i] = temp;
	}
}
