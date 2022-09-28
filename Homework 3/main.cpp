//1. Оптимизировать функции для работы с двумерными динамическими массивами;

#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int** arr, const int rows, const int cols);
void Print(int** arr, const int rows, const int cols);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int index);

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, int index);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, int index);

void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols, int index);

void main()
{
	setlocale(LC_ALL, "");
	int rows, cols, index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);       //выделение памяти
	FillRand(arr, rows, cols);       //заполнение
	Print(arr, rows, cols);          //вывод на экран

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

int** Allocate(const int rows, const int cols)           //выделяет память для двумерного массива
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)arr[i] = new int[cols] {};
	return arr;
}

void Clear(int** arr, const int rows)                     //удаляет двумерный динамический массив из памяти
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

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		(i == 0) ? (buffer[i] = new int [cols] {}) : (buffer[i] = arr[i - 1]);
	}
	delete[] arr;
	buffer[rows] = new int[cols] {};

	rows++;
	return buffer;
}

int** insert_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0, k = i; i < rows; i++)
	{
		(i == index) ? (buffer[i] = new int [cols] {}) : (buffer[i] = arr[k++]);
	}
	delete[] arr;
	buffer[rows] = new int[cols] {};

	rows++;
	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < (rows - 1); i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new int[cols];
	rows--;
	return buffer;
}

int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 1; i < rows; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new int[cols];
	rows--;
	return buffer;
}

int** erase_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0, k = i; i < rows; i++, k++)
	{
		(i == index) ? (buffer[i] = arr[k++ + 1]) : (buffer[i] = arr[k]);
	}

	delete[] arr;
	buffer[rows] = new int[cols];
	rows--;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void insert_col(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0, k = j; j < cols; j++, k++)
		{
			(j == index) ? (buffer[j++ + 1] = arr[i][k]) : (buffer[j] = arr[i][k]);
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

void erase_col(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0, k = j; j < cols; j++, k++)
		{
			(j == index) ? (buffer[j] = arr[i][k++ + 1]) : (buffer[j] = arr[i][k]);
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}