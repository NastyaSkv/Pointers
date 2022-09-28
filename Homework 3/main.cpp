//1. Оптимизировать функции для работы с двумерными динамическими массивами;

#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);

template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index);

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index);

template<typename T>void push_col_back(T** arr, const int rows, int& cols);
template<typename T>void push_col_front(T** arr, const int rows, int& cols);
template<typename T>void insert_col(T** arr, const int rows, int& cols, int index);

template<typename T>void pop_col_back(T** arr, const int rows, int& cols);
template<typename T>void pop_col_front(T** arr, const int rows, int& cols);
template<typename T>void erase_col(T** arr, const int rows, int& cols, int index);

void main()
{
	setlocale(LC_ALL, "");
	int rows, cols, index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	typedef int DataType;
	DataType** arr = Allocate<DataType>(rows, cols);       //выделение памяти

	FillRand(arr, rows, cols);                   //заполнение
	Print(arr, rows, cols);                      //вывод на экран

	/*cout << endl << "Добавим строку в конец массива: " << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Добавим строку в начало массива: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Введите индекс вставляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << endl << "Удалим строку в конце: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Удалим строку в начале: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Введите индекс удаляемой строки: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	*/
	cout << endl << "Добавим столбец в конец массива: " << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Добавим столбец в начало массива: " << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Введите индекс вставляемого столбца: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << endl << "Удалим столбец в конце: " << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	cout << endl << "Удалим столбец в начале: " << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Введите индекс удаляемого столбца: "; cin >> index;
    erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	
	Clear(arr, rows);
}

template<typename T>T** Allocate(const int rows, const int cols)           //выделяет память для двумерного массива
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)arr[i] = new T[cols] {};
	return arr;
}

template<typename T>void Clear(T** arr, const int rows)                     //удаляет двумерный динамический массив из памяти
{
	for (int i = 0; i < rows; delete[]arr[i++]);
	delete[] arr;
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
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}

template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		(i == 0) ? (buffer[i] = new T [cols] {}) : (buffer[i] = arr[i - 1]);
	}
	delete[] arr;
	buffer[rows] = new int[cols] {};

	rows++;
	return buffer;
}
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0, k = i; i < rows; i++)
	{
		(i == index) ? (buffer[i] = new T [cols] {}) : (buffer[i] = arr[k++]);
	}
	delete[] arr;
	buffer[rows] = new T[cols] {};

	rows++;
	return buffer;
}

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < (rows - 1); i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new T[cols];
	rows--;
	return buffer;
}
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows - 1];
	for (int i = 1; i < rows; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new T[cols];
	rows--;
	return buffer;
}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0, k = i; i < rows; i++, k++)
	{
		(i == index) ? (buffer[i] = arr[k++ + 1]) : (buffer[i] = arr[k]);
	}

	delete[] arr;
	buffer[rows] = new T[cols];
	rows--;
	return buffer;
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void insert_col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0, k = j; j < cols; j++, k++)
		{
			(j == index) ? (buffer[j++ + 1] = arr[i][k]) : (buffer[j] = arr[i][k]);
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void erase_col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0, k = j; j < cols; j++, k++)
		{
			(j == index) ? (buffer[j] = arr[i][k++ + 1]) : (buffer[j] = arr[i][k]);
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}