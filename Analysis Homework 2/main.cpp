#include<iostream>
#include<ctime>  //библиотека для измерения времени
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------------------\n"
#define DATA_TYPE int //это в С
template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);

template<typename T>void Print(T* arr, const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T* arr, int& n, T value);
template<typename T>T* pop_back(T* arr, int& n);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);

template<typename T>void push_col_back(T** arr, const int rows, int& cols);
template<typename T>void pop_col_back(T** arr, const int rows, int& cols);

//#define EXECUTION_TIME

void main()
{
	setlocale(LC_ALL, "");

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите элементов строки: "; cin >> cols;

	typedef double DataType;
	DataType** arr = Allocate<DataType>(rows, cols); // для С++
	//DATA_TYPE** arr = Allocate<DATA_TYPE>(rows, cols); // для С

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
	FillRand(arr[rows - 1], cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
#endif //!EXECUTION_TIME

#ifdef EXECUTION_TIME
	cout << "Строка добавлена! Mission complete :-)" << endl;
	clock_t end = clock();
	cout << "Время выполнения операции: " << end - start << " тактов" << endl;
#endif //EXECUTION_TIME

	arr = pop_row_back(arr, rows, cols);

#ifndef EXECUTION_TIME
	Print(arr, rows, cols);
	cout << delimiter << endl;
#endif //!EXECUTION_TIME

#ifdef EXECUTION_TIME
	cout << "Для добавления столбца нажмите любую клавишу...\n";
	system("pause");
	start = clock();
#endif //EXECUTION_TIME

	push_col_back(arr, rows, cols);

#ifndef EXECUTION_TIME
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand();
	Print(arr, rows, cols);
	cout << delimiter << endl;
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

template<typename T>T** Allocate(const int rows, const int cols)
{
	//1) Создаем массив указателей:
	T** arr = new T * [rows];
	//2) Выделяем память под строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int rows)
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
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 10000;
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования
		*(arr + i) = rand();
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
template<typename T>void Print(T* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
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

template<typename T>T* push_back(T* arr, int& n, T value)
{
	//1) Создаем буферный массив нужного размера:
	T* buffer = new T[n + 1];

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

template<typename T>T* pop_back(T* arr, int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	/*//1) Создаем буферный массив указателей нужного размера:
	T** buffer = new T * [rows + 1];
	//2) Копируем адреса строк из исходного массива указателей в буферный:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив указателей:
	delete[] arr;
	//4) Создаем новую (добавляемую строку):
	buffer[rows] = new T[cols]{};
	//5) После добавления строки в массив, количество строк массива увеличивается на 1:
	rows++;
	//6) Возвращаем адрес нового массива:
	return buffer;*/ 
	//оптимизируем ->
	return push_back(arr, rows, new T[cols]{});
}

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	//1) Удаляем строку из памяти:
	delete[] arr[rows - 1];
	/*//2) Переопределяем массив указателей:
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;*/ 
	//оптимизируем ->
	return pop_back(arr, rows);
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		/*//1) Создаем новую строку нужного размера (1 элемент больше):
		T* buffer = new T[cols + 1]{};
		//2) Копируем все элементы i-й строки в новую строку (buffer)
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) Удаляем исходную строку:
		delete[] arr[i];
		//4) Подменяем исходную строку новой:
		arr[i] = buffer;*/
		//оптимизируем ->
		arr[i] = push_back(arr[i], cols, T());
		cols--;
	}
	//5) После того как в каждую строку добавлен элемент, 
	//	 в массиве появляется еще один столбец
	cols++;
}

template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		/*T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;*/
		//оптимизируем ->
		arr[i] = pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}