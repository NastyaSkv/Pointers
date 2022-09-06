#include<iostream>
using namespace std;

void FillRand(int arr[], const int n); //объявл. через []
void Print(int* arr, const int n);     //объявл. через указатель
int* push_back(int* arr, int& n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	
	arr = push_back(arr, n, value);
	Print(arr, n);

	delete[] arr;

    //заполнение и вывод без использования функций
	/* 
	for (int i = 0; i < n; i++)
	{
		//обращаемся через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;
	}

	for (int i = 0; i < n; i++)
	{
		//обращаемся через оператор индексирования
		cout << arr[i] << "\t";
	}
	cout << endl;
	*/
}

void FillRand(int arr[], const int n)  //реализация ф-и через []
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int* arr, const int n)      //реализация ф-и через указатель
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* push_back(int* arr, int& n, int value)
{
	//1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2) Копируем содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) После того как все данные скопированы из исходного массива в буферный
	//исходный массив больше не нужен, и его можно удалить:
	delete[] arr;

	//4) Подменяем адрес исходного массива в указателе 'arr' адресом нового 
	//массива
	arr = buffer;

	//5) И только после этого можно написать вот так:
	arr[n] = value;
	//поскольку только сейчас в массиве 'arr' появился еще один элемент,
	//в который можно сохранить значение

	//6) После того как мы добавили в массив элемент, количество элементов массива
	//увеличивается на 1
	n++;

	//7) Mission complete - элемент добавлен!
	return(arr);
}