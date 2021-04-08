#include <iostream>
using namespace std;

struct dynamicArray {
	int n;
	int* arr;
};

void InputArray(dynamicArray &A) {
	cout << "Nhap so luong phan tu: ";
	cin >> A.n;
	A.arr = new int[A.n];
	for (int i = 0; i < A.n; i++)
	{
		cout << "Nhap A[" << i << "]: ";
		cin >> A.arr[i];
	}
	cout << endl;
}
void OutputArray(dynamicArray A) {
	for (int i = 0; i < A.n; i++)
	{
		cout << "A[" << i << "]: " << A.arr[i] << endl;
	}
	cout << endl;
}
int DemChanLe(dynamicArray A) {
	int chan = 0;
	int le = 0;
	for (int i = 0; i < A.n; i++)
	{
		if (A.arr[i] % 2 == 0) {
			chan++;
		}
		else {
			le++;
		}
	}
	return chan;
}
void TachMang(dynamicArray A, dynamicArray &mangchan, dynamicArray& mangle, int chan) {
	mangchan.arr = new int[chan];
	mangle.arr = new int[A.n - chan];
	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < A.n; i++)
	{
		if (A.arr[i] % 2 == 0) {
			mangchan.arr[temp1] = A.arr[i];
			temp1++;
		}
		else {
			mangle.arr[temp2] = A.arr[i];
			temp2++;
		}
	}
	mangchan.n = temp1;
	mangle.n = temp2;
	cout << "Mang chan:" << endl;
	OutputArray(mangchan);
	cout << "Mang le:" << endl;
	OutputArray(mangle);
}
int *FindX(dynamicArray A, int x) {
	int dem = 0, t = 0;
	for (int i = 0; i < A.n; i++)
	{
		if (A.arr[i] == x) {
			dem++;
		}
	}
	int* danhdau = new int[dem];
	cout << "Vi tri bang X: ";
	for (int j = 0; j < A.n; j++)
	{
		if (A.arr[j] == x) {
			danhdau[t] = j;
			t++;
			cout <<"A["<< j <<"], ";
		}
	}
	return danhdau;
}
void main() {
	dynamicArray A; int x;
	InputArray(A);
	cout << "Mang ban da nhap la: " << endl;
	OutputArray(A);
	dynamicArray mangchan;
	dynamicArray mangle;
	int chan = DemChanLe(A);
	TachMang(A, mangchan, mangle, chan);
	cout << "Nhap X: ";
	cin >> x;
	FindX(A, x);
}