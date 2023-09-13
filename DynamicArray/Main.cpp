#pragma once
#include "DynamicArray.h"


//возврат по значению
DynamicArray GetObj()  {
	DynamicArray obj(3);
	obj.Input();

	return obj;
}
void main() {
	int key = 0;
	DynamicArray a(5); // constructor 1 param
	a.Input();
	a.Output();
	DynamicArray b = a; // copy constructor
	b.Output();

	DynamicArray rezult = GetObj();

	// Ресайз
	cout << "Old size: " << a.GetSize() << endl;
	a.ReSize(2);
	cout << "New size: " << a.GetSize() << endl;
	a.Output();

	
	// Сортировка
	a.Input();
	cout << "Before sort: " << endl;
	a.Output();

	a.Sort();
	cout << "After sort: " << endl;
	a.Output();
	cout << endl;


	// Поиск ключа
	cout << "Search\nInput key: ";
	cin >> key;
	key = a.Search(key);

	if (key == -1)
		cout << "Key not found!" << endl;
	else
		cout << "Key potition (index): " << key << endl;
	cout << endl;


	// Ревёрс
	cout << "Before reverse: " << endl;
	a.Output();

	a.Reverse();

	cout << "After reverse: " << endl;
	a.Output();

	system("pause");
}