#include<iostream>
#include<ctime>  //библиотека для измерения времени
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
int** pop_row_back(int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);
void pop_col_back(int** arr, const int rows, int& cols);

//#define EXECUTION_TIME

void main()
{
	setlocale(LC_ALL, "");

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
#ifdef EXECUTION_TIME
	cout << "Memory allocated!" << endl;
	system("pause"); 
#endif //EXECUTION_TIME

#ifndef EXECUTION_TIME
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
#endif //!EXECUTION_TIME

	cout << "Добавляем строку в конец массива: " << endl;
	clock_t start = clock();
	arr = push_row_back(arr, rows, cols);

#ifndef EXECUTION_TIME
	Print(arr, rows, cols);
#endif //!EXECUTION_TIME

#ifdef EXECUTION_TIME
	cout << "Строка добавлена! Mission complete :-)" << endl;
	clock_t end = clock();
	cout << "Время выполнения операции: " << end - start << " тактов" << endl;
#endif //EXECUTION_TIME

	arr = pop_row_back(arr, rows, cols);

#ifndef EXECUTION_TIME
	Print(arr, rows, cols);
#endif //!EXECUTION_TIME

#ifdef EXECUTION_TIME
	cout << "Для добавления столбца нажмите любую клавишу...\n";
	system("pause");
	start = clock();
#endif //EXECUTION_TIME

	push_col_back(arr, rows, cols);

#ifndef EXECUTION_TIME
	Print(arr, rows, cols);
#endif //!EXECUTION_TIME

#ifdef EXECUTION_TIME
	end = clock();
	CLOCK_PER_SEC;
	cout << "Столбец добавлен! Mission complete :-)" << endl;
	cout << "Время выполнения операции: " << end - start << " тактов" << endl;
#endif //EXECUTION_TIME

	pop_col_back(arr, rows, cols);

#ifndef EXECUTION_TIME
	Print(arr, rows, cols);
#endif //!EXECUTION_TIME

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

int** pop_row_back(int** arr, int& rows, const int cols)
{
	//1) Удаляем строку из памяти:
	delete[] arr[rows - 1];
	//2) Переопределяем массив указателей:
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаем новую строку нужного размера (1 элемент больше):
		int* buffer = new int[cols + 1]{};
		//2) Копируем все элементы i-й строки в новую строку (buffer)
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) Удаляем исходную строку:
		delete[] arr[i];
		//4) Подменяем исходную строку новой:
		arr[i] = buffer;
	}
	//5) После того как в каждую строку добавлен элемент, 
	//	 в массиве появляется еще один столбец
	cols++;
}

void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols-1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}