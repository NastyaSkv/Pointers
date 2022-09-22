#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);

int** push_row_back(int** arr, int& rows, const int cols);

void main()
{
	setlocale(LC_ALL, "");   

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	cout << "Memory allocated!" << endl;
	system("pause");
	//FillRand(arr, rows, cols);
	//Print(arr, rows, cols);

	cout << "Добавляем строку в конец массива: " << endl;
	arr = push_row_back(arr, rows, cols);
	//Print(arr, rows, cols);
	cout << "Строка добавлена! Mission complete :-)" << endl;
	Clear(arr, rows);
}

int** Allocate(const int rows, const int cols)
{
	//1) Создаем массив указателей:
	int** arr = new int* [rows];
	//2) Выделяем память под строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования
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
void Print(int* arr, const int n)
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

	//3) После того как все данные скопированы из исходного массива в буферный,
	//	 исходный массив больше не нужен, и его можно удалить:
	delete[] arr;

	//4) Подменяем адрес исходного массива в указателе 'arr' адресом нового массива:
	arr = buffer;

	//5) И только после всего этого можно написать вот так:
	arr[n] = value;
	//поскольку только сейчас в массиве 'arr' появился еще один элемент, 
	//в который можно сохранить значение.

	//6) После того как мы добавили в массив элемент, количество элементов массива увеличивается на 1
	n++;
	//7) Mission complete - Элемент добавлен!
	return arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) Создаем буферный массив указателей нужного размера:
	int** buffer = new int* [rows + 1];
	//2) Копируем адреса строк из исходного массива указателей в буферный:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив указателей:
	delete[] arr;
	//4) Создаем новую (добавляемую строку):
	buffer[rows] = new int[cols] {};
	//5) После добавления строки в массив, количество строк массива увеличивается на 1:
	rows++;
	//6) Возвращаем адрес нового массива:
	return buffer;
}