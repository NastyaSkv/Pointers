/*
   1. ��� ������ ����� for ������� �� ����� ��� ��������� �� ���������� �������;
   2. ��� ������ ����� for ������� �� ����� �������� ���������� ����� �� ���� ���������;
   3. �������� ��������� ������� :
   Allocate;               - �������� ������ ��� ���������� �������
   Clear;			       - ������� ��������� ������������ ������ �� ������

   push_row_back(? ? ? );  - ��������� ������ � ����� �������
   push_row_front(? ? ? ); - ��������� ������ � ������ �������

   insert_row(? ? ? );	   - ��������� ������ � ������ �� �������

   pop_row_back(? ? ? );   - ������� ��������� ������ �� �������
   pop_row_front(? ? ? );  - ������� ������� ������ �� �������
   erase_row(? ? ? );	   - ������� ������ �� ������� �� ���������� �������

   push_col_back(? ? ? );  - ��������� ������� � ����� �������
   push_col_front(? ? ? ); - ��������� ������� � ������ �������
   insert_col(? ? ? );	   - ��������� ������� � ������ �� �������

   pop_col_back(? ? ? );   - ������� ��������� ������� �� �������
   pop_col_front(? ? ? );  - ������� ������� ������� �� �������
   erase_col(? ? ? );	   - ������� ������� �� ������� �� ���������� �������
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
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	int** arr = new int* [rows];

	Allocate(arr, rows, cols);       //��������� ������
	FillRand(arr, rows, cols);       //����������
	Print(arr, rows, cols);          //����� �� �����

	cout << endl << "������� ������ � ����� �������: " << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "������� ������ � ������ �������: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "������� ������ ����������� ������: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);



	Clear(arr, rows);
}

void Allocate(int** arr, const int rows, const int cols)            //�������� ������ ��� ���������� �������
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

void Clear(int** arr, const int rows)                     //������� ��������� ������������ ������ �� ������
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