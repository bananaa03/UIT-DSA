#include <iostream>
#include <iomanip>
using namespace std;

struct node {
	int info;
	struct node* pNext;
};
typedef struct node NODE;
struct list {
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void Init(LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
int IsEmpty(LIST l) {
	if (l.pHead == NULL) return 1;
	return 0;
}
NODE* GetNode(int x) {
	NODE* p = new NODE;
	if (p == NULL) return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST &l, NODE *p) {
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Input(LIST &l) {
	int n;
	cout << "Nhap n: "; cin >> n;
	Init(l);
	for (int i = 1; i <= n; i++) {
		int x;
		cout << "Nhap x: "; cin >> x;
		NODE* p = GetNode(x);
		if (p != NULL) AddTail(l, p);
	}
}
void Output(LIST l) {
	NODE* p = l.pHead;
	while (p != NULL) {
		cout << p->info;
		p = p->pNext;
	}
}
int DemLe(LIST l) {
	int d = 0;
	NODE* p = l.pHead;
	while (p != NULL) {
		if (p->info % 2 != 0) d++;
		p = p->pNext;
	}
	return d;
}
int Tong(LIST l) {
	int s = 0;
	NODE* p = l.pHead;
	while (p != NULL) {
		s = s + p->info;
		p = p->pNext;
	}
	return s;
}

int main() {
	LIST l;
	Input(l);
	cout << "Danh sach lien ket don ban dau: ";
	Output(l);
	int kq = DemLe(l);
	cout << endl << "So luong gia tri le trong danh sach: " << kq;
	kq = Tong(l);
	cout << endl << "Tong cac gia tri trong danh sach: " << kq;
	return 1;
}