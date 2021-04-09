#include <iostream>
using namespace std;

int** arr2D_Alloc(int& m, int& n);
void arr2D_input(int** a, int ma, int na);
int arr2D_negative(int** a, int ma, int na, int& max, int& min);
void arr2D_free(int** a, int m, int n);

int** arr2D_Alloc(int& m, int& n) {
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	cout << endl;
	int** a = new int* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}
	return a;
}
void arr2D_input(int** a, int ma, int na) {
	for (int i = 0; i < ma; i++)
	{	
		for (int j = 0; j < na; j++)
		{
			cout << "Nhap phan tu A[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
	
}

void arr2D_output(int** a, int ma, int na)
{
	for (int i = 0; i < ma; i++)
	{
		for (int j = 0; j < na; j++)
		{
			cout << "\nPhan tu A[" << i << "][" << j << "]: " << a[i][j];
		}
	}
}

int arr2D_negative(int** a, int ma, int na, int& max, int& min)
{
	min = a[0][0];
	max = a[0][0];
	int iin = 0, iax = 0, jin = 0, jax = 0;
	for (int i = 0; i < ma; i++)
	{
		for (int j = 0; j < na; j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
				iin = i;
				jin = j;
			}
			if (a[i][j] > max) 
			{
				max = a[i][j];
				iax = i;
				jax = j;
			}
		}
	}

	cout << "\n\nCap phan tu co hieu lon nhat: A[" << iin << "][" << jin << "] va A[" << iax << "][" << jax << "]" << endl;
	cout << "Hieu cua 2 cap phan tu la: " << max << " - " << min << " = " << max - min << endl;
	return 0;
}

void arr2D_free(int** a, int m, int n) 
{
	for (int i = 0; i < m; i++) {
		delete[]a[i];
	}
	delete[]a; 
}

void main() {
	int m, n;
	int max, min;
	int** A = arr2D_Alloc(m, n);
	arr2D_input(A, m, n);
	arr2D_output(A, m, n);
	arr2D_negative(A, m, n, max, min);
	arr2D_free(A, m, n);
}