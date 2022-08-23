#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	//объ€вление указателей
	int a = 2;       //объ€вление переменной
	int* pa = &a;
	cout << a << endl;    //вывод значени€ переменной 'а' на экран
	cout << &a << endl;   //вз€тие адреса переменной 'а' пр€мо при выводе 
	cout << pa << endl;   //вывод адреса переменной 'а', хран€щегос€ в указателе 'pa'
	cout << *pa << endl;  //разыменование указател€ 'pa' и вывод нв экран значени€ по адресу

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
		cout << *(arr + i) << "\t"; //выводим значени€ элементов
	}
	cout << endl;
}