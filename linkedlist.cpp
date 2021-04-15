#include <iostream>
using namespace std;

struct SinhVien {
	char name[20];
	int ID;
	int mark;
};
struct Node {
	SinhVien* data;
	Node* pNext;
};
struct List {
	Node* pHead = NULL;
	Node* pTail = NULL;
};
List *initList() {
	List* list = new List;
	
	return list;
}
SinhVien* NhapSinhVien()
{
	SinhVien* sv = new SinhVien;
	cout << "Nhap MSSV:";
	cin >> sv->ID;
	cin.ignore();
	cout << "Nhap ho va ten:";
	cin.get(sv->name,20);
	cout << "Nhap diem: ";
	cin >> sv->mark;
	return sv;
}
Node* CreateNode(SinhVien* sv)
{
	Node* pNode = new Node;
	if (pNode != NULL)
	{
		pNode->data = sv;
		pNode->pNext = NULL;
	}
	else
	{
		cout << "cap phat bo nho that bai!!!";
	}
	return pNode;
}
void InsertHead(List*& list, SinhVien* sv) {
	Node* pNode = CreateNode(sv);
	pNode->pNext = list->pHead;
	list->pHead = pNode;
}
//
//void InsertLast(List*& list, SinhVien* sv)
//{
//	Node* pNode = CreateNode(sv);
//	if (list->pHead == NULL)
//	{
//		list->pHead = pNode;
//	}
//	else
//	{
//		Node* pTmp = list->pHead;
//
//		while (pTmp->pNext != NULL)
//		{
//			pTmp = pTmp->pNext;
//		}
//		pTmp->pNext = pNode;
//	}
//}
void PrintList(List* list)
{
	Node* pTmp = list->pHead;
	if (pTmp == NULL)
	{
		cout << "Danh sach rong";
		return;
	}
	while (pTmp != NULL)
	{
		SinhVien* sv = pTmp->data;
		cout << sv->ID << "  " << sv->name << "  " << sv->mark << endl;
		pTmp = pTmp->pNext;	
	}
}
void main() {
	List *list = initList();
	SinhVien* sv;
	int n = 2;
	for (int i = 0; i < n; i++)
	{
		sv = NhapSinhVien();
		InsertHead(list, sv);
	}
	PrintList(list);
}