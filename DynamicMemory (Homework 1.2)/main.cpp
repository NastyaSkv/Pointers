// 2) � ������ DynamicMemory �������� ��������� �������:
//       push_front(); - ��������� �������� � ������ �������
//       insert(); - ��������� �������� � ������ �� ���������� �������
//       pop_back(); - ������� �������� �� ����� �������
//       pop_front(); - ������� �������� c ������ �������
//       erase(); - ������� �������� �� ������� �� ���������� �������
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
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� �������� �����: "; cin >> value;

	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� �������� ������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� ����������� ��������: "; cin >> value;
	
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
	int* buffer = new int[n + 1];               //1) ������� �������� ������ ������� �������
	
	for (int i = 0; i < n; i++)                 //2) �������� ���������� ��������� ������� � ��������:
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	arr = buffer; 	                            //3) ��������� ����� ��� ������� � ��������� 'arr' ������� ������ 
	arr[n] = value;

	n++;
	return(arr);
}

int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n+1];               //1) ������� �������� ������ ������� �������

	for (int i = 1; i <= n; i++)                 //2) �������� ���������� ��������� ������� � ��������:
	{
		buffer[i] = arr[i-1];
	}

	delete[] arr;
	arr = buffer; 	                            //3) ��������� ����� ��� ������� � ��������� 'arr' ������� ������ 
	arr[0] = value;

	n++;
	return(arr);
}

int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];               //1) ������� �������� ������ ������� �������

	for (int i = 1; i <= n; i++)                 //2) �������� ���������� ��������� ������� � ��������:
	{
		buffer[i] = arr[i - 1];
	}

	delete[] arr;
	arr = buffer; 	                            //3) ��������� ����� ��� ������� � ��������� 'arr' ������� ������ 
	arr[0] = value;

	n++;
	return(arr);
}