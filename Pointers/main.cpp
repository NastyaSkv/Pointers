#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	//объявление указателей
	int a = 2;       //объявление переменной
	int* pa = &a;
	cout << a << endl;    //вывод значения переменной 'а' на экран
	cout << &a << endl;   //взятие адреса переменной 'а' прямо при выводе 
	cout << pa << endl;   //вывод адреса переменной 'а', хранящегося в указателе 'pa'
	cout << *pa << endl;  //разыменование указателя 'pa' и вывод нв экран значения по адресу

	//пример
	int* pb;
	int b = 3;
	             //*pb = &b; - пример ошибки
	pb = &b;
	cout << b << endl;
	cout << &b << endl;
	cout << pb << endl;
	cout << *pb << endl;
#endif

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;    //вывели адрес массива
	cout << *arr << endl;   //разыменовали массив
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t"; //выводим значения элементов
	}
	cout << endl;
}