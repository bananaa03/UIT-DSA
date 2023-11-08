#include <iostream>
#include <iomanip>
using namespace std;

struct NODE
{
	int info;
	struct NODE* pNext;
};

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

void Init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}

//1
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void Input(LIST& l)
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "Nhap x: ";
		cin >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
}

void Output(LIST l)
{
	NODE* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}


//2
int DemNode(LIST l)
{
	int d = 0;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		p = p->pNext;
	}
	return d;
}

//3
NODE* FindNode(LIST l, int x)
{
	NODE* p = l.pHead;
	while (p->info != x)
	{
		p = p->pNext;
	}
	return p;
}

//4
NODE* TachHead(LIST &l)
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail)
	{
		NODE* p = l.pHead;
		l.pHead = l.pTail = NULL;
		return p;
	}

	NODE* p = l.pHead;
    l.pHead = l.pHead->pNext;
	p->pNext = NULL;
	return p;
}

//5
int TongGiaTriChan(LIST l)
{
	int s = 0;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		if (p->info % 2 == 0)
			s = s + p->info;
		p = p->pNext;
	}
	return s;
}

//6
double Max(LIST l)
{
	NODE* p = l.pHead;
	double max = p->info;
	while (p != NULL)
	{
		if (p->info > max) max = p->info;
		p = p->pNext;
	}
	return max;
}

//7
NODE* TimViTri(LIST l)
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail)
		return NULL;
	NODE* lc = l.pHead;
	while (lc->pNext!=NULL)
	{
		lc = lc->pNext;
	}
	return lc;
}

//8
NODE* TachTail(LIST &l)
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail)
	{
		NODE* p = l.pHead;
		l.pHead = l.pTail = NULL;
		return p;
	}
	NODE* p = l.pHead;
	while (p == l.pTail)
	{
		NODE* k = l.pTail;
		p->pNext = NULL;
		l.pTail = p;
	}
	return p;
}

//9
bool KiemTraNodeCoTrongList(LIST l, NODE* q)
{
	for (NODE* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (q == i)
			return true;
	}
	return false;
}

//11
NODE* TachNODE(LIST &l, NODE* p)
{
	if (p == l.pHead)
	{
		TachHead(l);
		return p;
	}
	if (p == l.pTail)
	{
		TachTail(l);
		return p;
	}
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k == p)
		{
			k->pNext = p->pNext;
			p->pNext = NULL;
		}
	}
	return p;
}

