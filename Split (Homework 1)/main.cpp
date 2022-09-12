// 1) ������ �� 10-� ��������� ��������� ���������� ������� � ��������� �� ��� ������� even[] � odd[] ���������� ���������� �������.
//������ even[] �������� ������ �������� �� ��������� �������, � ������ odd[] - �������� �������� �� ��������� �������.

#include<iostream>
using namespace std;

void FillRand(int* arr, const int n);
void Print(int* arr, const int n);
void FillRand_2(int* arr, const int n, int* even, const int t, int* odd, const int w);
void Print_2(int* even, const int t);
void Print_3(int* odd, const int w);

void main()
{
	setlocale(LC_ALL, " ");
	
	int t = 0, w = 0;
	int n = 10;
	int* arr = new int[n];

	FillRand(arr, n);                                              //���������� �������
	Print(arr, n);                                                 //����� �������
	cout << endl << endl;

	for (int i = 0; i < n; i++)                                    //������� ���-�� ������ � ��������          
	{
		(*(arr + i) % 2 == 0) ? t++ : w++;
	}

	int* even = new int[t];                                        //������ ��� ������
	int* odd = new int[w];                                         //������ ��� ��������
	
	FillRand_2(arr, n, even, t, odd, w);                           //���������� ��������
	Print_2(even, t);                                              //����� �������
	Print_3(odd, w);                                               //����� �������

	delete[] arr;
	delete[] even;
	delete[] odd;
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

void FillRand_2(int* arr, const int n, int* even, const int t, int* odd, const int w)
{
	int j = 0, z = 0;
	for (int i = 0; i < n; i++)
	{
		(*(arr + i) % 2 == 0) ? (even[j] = arr[i], j++) : (odd[z] = arr[i], z++);
	}
}

void Print_2(int* even, const int t)
{
	for (int i = 0; i < t; i++)
	{
		cout << even[i] << "\t";
	}
	cout << endl;
}

void Print_3(int* odd, const int w)
{
	for (int i = 0; i < w; i++)
	{
		cout << odd[i] << "\t";
	}
	cout << endl;
}