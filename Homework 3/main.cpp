//1. �������������� ������� ��� ������ � ���������� ������������� ���������;

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

int** push_col_back(int** arr, const int rows, int& cols);

int** push_col_front(int** arr, int& rows, int& cols);
int** insert_col(int** arr, int& rows, int& cols, int index);
int** pop_col_back(int** arr, int& rows, int& cols);
int** pop_col_front(int** arr, int& rows, int& cols);
int** erase_col(int** arr, int& rows, int& cols, int index);

void main()
{
	setlocale(LC_ALL, "");
	int rows, cols, index;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;

	int** arr = Allocate(rows, cols);       //��������� ������
	FillRand(arr, rows, cols);       //����������
	Print(arr, rows, cols);          //����� �� �����

	/*cout << endl << "������� ������ � ����� �������: " << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "������� ������ � ������ �������: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "������� ������ ����������� ������: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << endl << "������ ������ � �����: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "������ ������ � ������: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "������� ������ ��������� ������: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	*/
	cout << endl << "������� ������� � ����� �������: " << endl;
	arr = push_col_back(arr, rows, cols);
	
	Print(arr, rows, cols);

	/*
	cout << endl << "������� ������� � ������ �������: " << endl;
	arr = push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "������� ������ ������������ �������: "; cin >> index;
	arr = insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << endl << "������ ������� � �����: " << endl;
	arr = pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "������ ������� � ������: " << endl;
	arr = pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << endl << "������� ������ ���������� �������: "; cin >> index;
	arr = erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	*/
	Clear(arr, rows);
}

int** Allocate(const int rows, const int cols)           //�������� ������ ��� ���������� �������
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)arr[i] = new int[cols] {};
	return arr;
}

void Clear(int** arr, const int rows)                     //������� ��������� ������������ ������ �� ������
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

int** push_col_back(int** arr, const int rows, int& cols)
{
	/*int** buffer = new int* [cols + 1];
	for (int i = 0; i < ; i++)
	{
		buffer[i] = arr[i];
	}*/

	int** buffer = new int* [cols+1];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			(j == cols - 1) ? (buffer[j] = {}) : (buffer[j] = arr[j]);
			//buffer[j] = arr[j];
		}
	}
	delete[] arr;
	//buffer[rows] = new int[cols+1] {};
	cols++;
	return buffer;

}
/*
int** push_col_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows];
	Allocate(buffer, rows, cols + 1);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <= cols; j++)
		{
			buffer[i][j] = arr[i][j - 1];
		}
	}
	Clear(arr, rows);

	arr = buffer;
	for (int i = 0; i < rows; i++)
	{
		arr[i][0] = {};
	}
	cols++;
	return(arr);
}

int** insert_col(int** arr, int& rows, int& cols, int index)
{
	int** buffer = new int* [rows];
	Allocate(buffer, rows, cols + 1);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0, k = j; j <= cols && k <= cols; j++)
		{
			(j == index) ? (buffer[i][j] = {}) : (buffer[i][j] = arr[i][k], k++);
		}
	}
	Clear(arr, rows);
	arr = buffer;
	cols++;
	return(arr);
}

int** pop_col_back(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows];
	Allocate(buffer, rows, cols - 1);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, rows);

	arr = buffer;
	cols--;
	return(arr);
}

int** pop_col_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows];
	Allocate(buffer, rows, cols - 1);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
	}
	Clear(arr, rows);
	arr = buffer;
	cols--;
	return(arr);
}

int** erase_col(int** arr, int& rows, int& cols, int index)
{
	int** buffer = new int* [rows];
	Allocate(buffer, rows, cols - 1);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0, k = j; j < cols && k < (cols); j++, k++)
		{
			if (j == (cols - 1))break;
			(j == index) ? (buffer[i][j] = arr[i][k + 1], k++) : (buffer[i][j] = arr[i][k]);
		}
	}
	Clear(arr, rows);
	arr = buffer;
	cols--;
	return(arr);
}*/