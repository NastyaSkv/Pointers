#include<iostream>
#include<ctime>  //���������� ��� ��������� �������
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


void main()
{
	setlocale(LC_ALL, "");   

	int rows, cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ��������� ������: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	cout << "Memory allocated!" << endl;
	//system("pause");
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "��������� ������ � ����� �������: " << endl;
	//clock_t start = clock();
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������ ���������! Mission complete :-)" << endl;
	//clock_t end = clock();
	//cout << "����� ���������� ��������: " << end - start << " ������" << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	//cout << "��� ���������� ������� ������� ����� �������...\n";
	//system("pause");
	//start = clock();
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	//end = clock();
	//CLOCK_PER_SEC;
	cout << "������� ��������! Mission complete :-)" << endl;
	//cout << "����� ���������� ��������: " << end - start << " ������" << endl;

	Clear(arr, rows);
}

int** Allocate(const int rows, const int cols)
{
	//1) ������� ������ ����������:
	int** arr = new int* [rows];
	//2) �������� ������ ��� ������ ���������� �������:
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
		//����� ���������� ���������� � �������� �������������
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
	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1];

	//2) �������� ���������� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) ����� ���� ��� ��� ������ ����������� �� ��������� ������� � ��������,
	//	 �������� ������ ������ �� �����, � ��� ����� �������:
	delete[] arr;

	//4) ��������� ����� ��������� ������� � ��������� 'arr' ������� ������ �������:
	arr = buffer;

	//5) � ������ ����� ����� ����� ����� �������� ��� ���:
	arr[n] = value;
	//��������� ������ ������ � ������� 'arr' �������� ��� ���� �������, 
	//� ������� ����� ��������� ��������.

	//6) ����� ���� ��� �� �������� � ������ �������, ���������� ��������� ������� ������������� �� 1
	n++;
	//7) Mission complete - ������� ��������!
	return arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) ������� �������� ������ ���������� ������� �������:
	int** buffer = new int* [rows + 1];
	//2) �������� ������ ����� �� ��������� ������� ���������� � ��������:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������ ����������:
	delete[] arr;
	//4) ������� ����� (����������� ������):
	buffer[rows] = new int[cols] {};
	//5) ����� ���������� ������ � ������, ���������� ����� ������� ������������� �� 1:
	rows++;
	//6) ���������� ����� ������ �������:
	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	//1) ������� ������ �� ������:
	delete[] arr[rows - 1];
	//2) �������������� ������ ����������:
	int** buffer = new int*[--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) ������� ����� ������ ������� ������� (1 ������� ������):
		int* buffer = new int[cols + 1]{};
		//2) �������� ��� �������� i-� ������ � ����� ������ (buffer)
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) ������� �������� ������:
		delete[] arr[i];
		//4) ��������� �������� ������ �����:
		arr[i] = buffer;
	}
	//5) ����� ���� ��� � ������ ������ �������� �������, 
	//	 � ������� ���������� ��� ���� �������
	cols++;
}