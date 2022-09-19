/*
   1. При помощи цикла for вывести на экран ряд Фибоначчи до указанного предела;
   2. При помощи цикла for вывести на экран заданное количество чисел из ряда Фибоначчи;
   3. Добавить следующие функции :
   Allocate;               - выделяет память для двумерного массива
   Clear;			       - удаляет двумерный динамический массив из памяти

   push_row_back(? ? ? );  - добавляет строку в конец массива
   push_row_front(? ? ? ); - добавляет строку в начало массива

   insert_row(? ? ? );	   - вставляет строку в массив по индексу

   pop_row_back(? ? ? );   - удаляет последнюю строку из массива
   pop_row_front(? ? ? );  - удаляет нулевую строку из массива
   erase_row(? ? ? );	   - удаляет строку из массива по указанному индексу

   push_col_back(? ? ? );  - добавляет столбец в конец массива
   push_col_front(? ? ? ); - добавляет столбец в начало массива
   insert_col(? ? ? );	   - вставляет столбец в массив по индексу

   pop_col_back(? ? ? );   - удаляет последний столбец из массива
   pop_col_front(? ? ? );  - удаляет нулевой столбец из массива
   erase_col(? ? ? );	   - удаляет столбец из массива по указанному индексу
*/
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

void Allocate(int** arr, const int rows, const int cols);
void FillRand(int** arr, const int rows, const int cols);
void Print(int** arr, const int rows, const int cols);
void Clear(int** arr, const int rows);
int** push_row_back(int** arr, int& rows, int& cols);
int** push_row_front(int** arr, int& rows, int& cols);
int** insert_row(int** arr, int& rows, int& cols, int index);

void main()
{
	setlocale(LC_ALL, "");
	int rows, cols, index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = new int* [rows];

	Allocate(arr, rows, cols);       //выделение памяти
	FillRand(arr, rows, cols);       //заполнение
	Print(arr, rows, cols);          //вывод на экран

	cout << endl << "Добавим строку в конец массива: " << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Добавим строку в начало массива: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "Введите индекс вставляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);



	Clear(arr, rows);
}

void Allocate(int** arr, const int rows, const int cols)            //выделяет память для двумерного массива
{
	for (int i = 0; i < rows; arr[i++] = new int[cols]);
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

void Clear(int** arr, const int rows)                     //удаляет двумерный динамический массив из памяти
{
	for (int i = 0; i < rows; delete[]arr[i++]);
	delete[] arr;
}

int** push_row_back(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows + 1];
	Allocate(buffer, rows + 1, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, rows);

	arr = buffer;

	for (int j = 0; j < cols; j++)
	{
		arr[rows][j] = {};
	}
	rows++;
	return(arr);
}

int** push_row_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows + 1];
	Allocate(buffer, rows + 1, cols);

	for (int i = 1; i <= rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i - 1][j];
		}
	}
	Clear(arr, rows);
	arr = buffer;
	for (int j = 0; j < cols; j++)
	{
		arr[0][j] = {};
	}
	rows++;
	return(arr);
}

int** insert_row(int** arr, int& rows, int& cols, int index)
{
	int** buffer = new int* [rows + 1];
	Allocate(buffer, rows + 1, cols);
	/*
	for (int i = 0, k = i; i <= rows && k <= rows; i++)
	{
		if (i == index)
		{
			for (int j = 0; j < cols; j++)
			{
				buffer[i][j] = {};
			}
		}
		else
		{
			for (int j = 0; j < cols; j++)
			{
				buffer[i][j] = arr[k][j];
			}
			//i++;
			k++;
		}
	}
	*/
	for (int i = 0, k = i; i <= rows && k <= rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			(i == index) ? (buffer[i][j] = {}) : (buffer[i][j] = arr[k][j]);
		}
		(i == index) ? k : (k++);
	}
	Clear(arr, rows);
	arr = buffer;
	rows++;
	return(arr);
}