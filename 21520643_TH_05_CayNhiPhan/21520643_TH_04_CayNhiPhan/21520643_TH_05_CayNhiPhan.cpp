#include <iostream>
using namespace std;

struct node
{
	int info;
	struct node* pLeft;
	struct node* pRight;
};
typedef struct node NODE;

typedef NODE* TREE;

void Init(TREE& t)
{
	t = NULL;
}

NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

int InsertNode(TREE& t, int x) {
	if (t != NULL) {
		int rValue = rand();
		if (rValue % 2 == 0)
			return InsertNode(t->pRight, x);
		return InsertNode(t->pLeft, x);
	}
	t = GetNode(x);
	if (t == NULL)
		return -1;
}

int IsEmpty(TREE t) {
	if (t == NULL)
		return 1;
	return 0;
}

void Input(TREE& t)
{
	cout << "Nhap so luong node: ";
	int n;
	cin >> n;

	Init(t);
	int x;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap x: ";
		cin >> x;
		//if (t != NULL)
			InsertNode(t, x);
	}
}

void Output(TREE t) {
	if (t == NULL) return;
	Output(t->pLeft);
	cout << t->info << " ";
	Output(t->pRight);
}

int DemNode(TREE t)
{
	if (t == NULL)
		return 0;
	int a = DemNode(t->pLeft);
	int b = DemNode(t->pRight);
	return 1 + a + b;
}

int Tong(TREE t)
{
	if (t == NULL) return 0;
	int a = Tong(t->pLeft);
	int b = Tong(t->pRight);
	return t->info + a + b;
}

double TBC(TREE t)
{
	if (DemNode(t) == 0)
		return 0;
	return double(Tong(t) / DemNode(t));
}

int DemNodeDuong(TREE t)
{
	if (t == NULL) return 0;
	int a = DemNodeDuong(t->pLeft);
	int b = DemNodeDuong(t->pRight);
	if (t->info > 0)
		return 1 + a + b;
	return a + b;
}

int TongDuong(TREE t)
{
	if (t == NULL)
		return 0;
	int a = TongDuong(t->pLeft);
	int b = TongDuong(t->pRight);
	if (t->info > 0)
		return t->info + a + b;
	return a + b;
}

double TBCDuong(TREE t)
{
	if (DemNodeDuong == 0)
		return 0;
	return double(TongDuong(t) / DemNodeDuong(t));
}

int DemNodeAm(TREE t)
{
	if (t == NULL) return 0;
	int a = DemNodeAm(t->pLeft);
	int b = DemNodeAm(t->pRight);
	if (t->info < 0)
		return 1 + a + b;
	return a + b;
}

int TongAm(TREE t)
{
	if (t == NULL)
		return 0;
	int a = TongAm(t->pLeft);
	int b = TongAm(t->pRight);
	if (t->info < 0)
		return t->info + a + b;
	return a + b;
}

double TBCAm(TREE t)
{
	if (DemNodeAm == 0)
		return 0;
	return double(TongAm(t) / DemNodeAm(t));
}

double TiSoR(TREE t)
{
	if (TongAm(t) == 0 || TongDuong(t) == 0)
		return 0;
	return double(TongDuong(t) / TongAm(t));
}

void XuatChan(TREE t)
{
	if (t == 0) return;
	XuatChan(t->pLeft);
	XuatChan(t->pRight);
	if (t->info % 2 == 0)
		cout << t->info << " ";
}

void XuatDiaChi(TREE t, int a, int b)
{
	if (t != NULL)
	{
		XuatDiaChi(t->pLeft, a, b);
		if (t->info > a && t->info < b)
			cout << &t->info;
		XuatDiaChi(t->pRight, a, b);
	}
}

int OneChild (TREE t)
{
	if (t == NULL)
		return 0;
	int a = OneChild(t->pLeft);
	int b = OneChild(t->pRight);
	if ((t->pLeft == NULL && t->pRight != NULL) || (t->pLeft != NULL && t->pRight == NULL))
		return (a + b + 1);
	return (a + b);
}

int ChieuCao(TREE t)
{
	if (t == NULL)
		return 0;
	int a = ChieuCao(t->pLeft);
	int b = ChieuCao(t->pRight);
	if (a > b)
		return (a + 1);
	return (b + 1);
}


/*int main()
{
	TREE t;
	Init(t);
	Input(t);
	cout << "Xuat thong tin cay: ";
	Output(t);
	cout << endl;

	//cout << "Tong so node trong cay: " << DemNode(t) << endl;
	//cout << "Tong cac node: " << Tong(t) << endl;
	cout << "Trung binh cong cac node trong cay: " << TBC(t) << endl;

	//cout << "So node duong trong cay: " << DemNodeDuong(t) << endl;
	//cout << "Tong cac node duong: " << TongDuong(t) << endl;
	cout << "Trung binh cong cac node duong trong cay: " << TBCDuong(t) << endl;

	//cout << "So node am trong cay: " << DemNodeAm(t) << endl;
	//cout << "Tong cac node am: " << TongAm(t) << endl;
	cout << "Trung binh cong cac node am trong cay: " << TBCAm(t) << endl;

	cout << "Ti so R: " << TiSoR(t) << endl;

	cout << "Cac gia tri chan trong cay: ";
	XuatChan(t);
	cout << endl;

	cout << "Chieu cao cay nhi phan: " << ChieuCao(t) << endl;

	cout << "So node co dung mot con: " << OneChild(t) << endl;
	
}*/