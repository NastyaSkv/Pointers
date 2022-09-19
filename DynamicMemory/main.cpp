#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

void FillRand(int arr[], const int n); //объявл. через []
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int n);     //объявл. через указатель
void Print(int** arr, const int rows, const int cols);
int* push_back(int* arr, int& n, int value);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
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

#endif

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	//1) Создаем массив указателей:
	int** arr = new int* [rows];

	//2) Выделяем память под строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	//удаляем двумерный массив:
	// 1)сначала удаляются строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	// 2) удаляем массив указателей:
	delete[] arr;


#endif
}

void FillRand(int arr[], const int n)  //реализация ф-и через []
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
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