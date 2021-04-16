#include <iostream>
#include<time.h>
#include "stdlib.h"
using namespace std;

struct SinhVien {
	char name[20];
	int ID;
	int mark;
};
struct Node {
	SinhVien data;
	Node* pNext;
};
struct List {
	Node* pHead = NULL;
	Node* pTail = NULL;
}; 
int rando();
char* randname(int n, SinhVien& sv);

List *initList() {
	List* list = new List;
	return list;
}
SinhVien NhapSinhVien()
{
	SinhVien sv;
	cout << "Nhap MSSV:";
	cin >> sv.ID;
	cin.ignore();
	cout << "Nhap ho va ten:";
	cin.get(sv.name,20);
	cout << "Nhap diem: ";
	cin >> sv.mark;
	return sv;
}
SinhVien RandomSV(int n)
{
	SinhVien sv;
	sv.ID = rando();
	randname(rando(), sv);
	sv.mark = rando();
	return sv;
}
Node* CreateNode(SinhVien sv)
{
	Node* pNode = new Node;
	if (pNode != NULL)
	{
		pNode->data = sv;
		pNode->pNext = NULL;
	}
	else
	{
		cout << "Cap phat bo nho that bai!!!";
	}
	return pNode;
}
void InsertHead(List*& list, SinhVien sv) {
	Node* pNode = CreateNode(sv);
	pNode->pNext = list->pHead;
	list->pHead = pNode;
}
void InsertAfterHead(List*& list, SinhVien sv)
{
	Node* pNode = CreateNode(sv);
	if (list->pHead != NULL)
	{
		pNode->pNext = list->pHead->pNext;
		list->pHead->pNext = pNode;
	}
}
void InsertBeforeTail(List*& list, SinhVien sv) {
	Node* pNode = CreateNode(sv);
	pNode->pNext = list->pTail;
	if (list->pHead != NULL)
	{
		Node* pTmp = list->pHead;
		while (pTmp->pNext != list->pTail)
		{
			
			pTmp = pTmp->pNext;
		} 
		pTmp->pNext = pNode;
	}

}
void InsertLast(List*& list, SinhVien sv)
{
	Node* pNode = CreateNode(sv);
	if (list->pHead != NULL)
	{
		Node* pTmp = list->pHead;
		while (pTmp->pNext!= NULL)
		{
			pTmp = pTmp->pNext;
		}
		pTmp->pNext = pNode;
		list->pTail = pNode;
	}
	else
	{
		list->pHead = pNode;
	}
}
int rando() {
	int iSecret, iGuess;
	srand(time(NULL));
	iSecret = rand() % 10 + 1;
	return iSecret;
}
char* randname(int n, SinhVien &sv) {
	
	switch (n)
	{
	case 1:
		strcpy_s(sv.name,"Tin");
		break;
	case 2:
		strcpy_s(sv.name, "Vuong");
		break;
	case 3:
		strcpy_s(sv.name, "Quang");
		break;
	case 4:
		strcpy_s(sv.name, "Tuan");
		break;
	case 5:
		strcpy_s(sv.name, "Minh");
		break;
	case 6:
		strcpy_s(sv.name, "Phuc");
		break;
	case 7:
		strcpy_s(sv.name, "Quan");
		break;
	case 8:
		strcpy_s(sv.name, "Linh");
		break;
	case 9:
		strcpy_s(sv.name, "Tri");
		break;
	case 10:
		strcpy_s(sv.name, "Loc");
		break;
	}
	return sv.name;
}
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
		SinhVien sv = pTmp->data;
		cout << sv.ID << "  " << sv.name << "  " << sv.mark << endl;
		pTmp = pTmp->pNext;	
	}
}
void main() {
	List *list = initList();
	SinhVien sv;
	
	
	sv = NhapSinhVien();
	InsertHead(list, sv);
	sv = NhapSinhVien();
	InsertLast(list, sv);
	sv = NhapSinhVien();
	InsertAfterHead(list, sv);
	sv = NhapSinhVien();
	InsertBeforeTail(list, sv);
	for (int i = 0; i < 5; i++)
	{
		sv = RandomSV(i);
		InsertHead(list, sv);
	}
	PrintList(list);
}