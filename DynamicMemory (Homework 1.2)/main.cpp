// 2) В проект DynamicMemory добавить следующие функции:
//       push_front(); - добавляет значение в начало массива
//       insert(); - добавляет значение в массив по указанному индексу
//       pop_back(); - удаляет значение из конца массива
//       pop_front(); - удаляет значение c начала массива
//       erase(); - удаляет значение из массива по указанному индексу
#include<iostream>
using namespace std;

void FillRand(int* arr, const int n); 
void Print(int* arr, const int n);     
int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n, index;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение назад: "; cin >> value;

	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение вперед: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;
	
	delete[] arr;
}

void FillRand(int* arr, const int n)  
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
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

int* push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];               //1) Создаем буферный массив нужного размера
	
	for (int i = 0; i < n; i++)                 //2) Копируем содержимое исходного массива в буферный:
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	arr = buffer; 	                            //3) Подменяем адрес исх массива в указателе 'arr' адресом нового 
	arr[n] = value;

	n++;
	return(arr);
}

int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n+1];               //1) Создаем буферный массив нужного размера

	for (int i = 1; i <= n; i++)                 //2) Копируем содержимое исходного массива в буферный:
	{
		buffer[i] = arr[i-1];
	}

	delete[] arr;
	arr = buffer; 	                            //3) Подменяем адрес исх массива в указателе 'arr' адресом нового 
	arr[0] = value;

	n++;
	return(arr);
}

int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];               //1) Создаем буферный массив нужного размера

	for (int i = 1; i <= n; i++)                 //2) Копируем содержимое исходного массива в буферный:
	{
		buffer[i] = arr[i - 1];
	}

	delete[] arr;
	arr = buffer; 	                            //3) Подменяем адрес исх массива в указателе 'arr' адресом нового 
	arr[0] = value;

	n++;
	return(arr);
}