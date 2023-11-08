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

void NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->info << " ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

void RLN(TREE t)
{
	if (t != NULL)
	{
		RLN(t->pRight);
		RLN(t->pLeft);
		cout << t->info << " ";
	}
}

int OneChild(TREE t)
{
	if (t == NULL)
		return 0;
	int a = OneChild(t->pLeft);
	int b = OneChild(t->pRight);
	if ((t->pLeft == NULL && t->pRight != NULL) || (t->pLeft != NULL && t->pRight == NULL))
		return t->info;
}

struct dt
{
	NODE* p;
	int h;
};
typedef struct dt DT;
struct stack
{
	int n;
	DT a[100];
};
typedef struct stack STACK;


void Init(STACK& st)
{
	st.n = 0;
}
int IsEmpty(STACK st)
{
	if (st.n == 0)
		return 1;
	return 0;
}

int IsFulll(STACK st)
{
	if (st.n == 100)
		return 1;
	return 0;
}
void Push(STACK& st, DT x)
{
	st.a[st.n] = x;
	st.n++;
}
DT Pop(STACK& st)
{
	DT x = st.a[st.n - 1];
	st.n--;
	return x;
}

int ChieuCaoS(TREE t)
{
	int h = 0;
	STACK stk;
	Init(stk);
	if (t != NULL)
	{
		DT ob = { t,1 };
		Push(stk, ob);
	}
	while (IsEmpty(stk) == 0)
	{
		DT ob = Pop(stk);
		if (ob.h > h)
			h = ob.h;
		if (ob.p->pLeft != NULL)
		{
			ob = { ob.p->pLeft,ob.h + 1 };
			Push(stk, ob);
		}
		if (ob.p->pRight != NULL)
		{
			ob = { ob.p->pRight,ob.h + 1 };
			Push(stk, ob);
		}
	}
	return h;
}

void NodeThayThe(TREE& t, TREE& p)
{
	if (t->pLeft != NULL)
		NodeThayThe(t->pLeft, p);
	else
	{
		p->info = t->info;
		p = t;
		t = t->pRight;
	}
}

void Delete(TREE& t, int x)
{
	if (t != NULL)
	{
		if (t->info < x) Delete(t->pRight, x);
		else if (t->info > x) Delete(t->pLeft, x);
		else
		{
			NODE* p = t;
			if (t->pLeft == NULL) t = t->pRight;
			else if (t->pRight == NULL) t = t->pLeft;
			else
				NodeThayThe(t->pRight, p);
			delete p;
		}
	}
	//else  cout << "Khong tim thay phan tu can xoa!";
}

int main()
{
	TREE t;
	int root;
	Init(t);
	root = InsertNode(t, 11);
	root = InsertNode(t, 6);
	root = InsertNode(t, 8);
	root = InsertNode(t, 19);
	root = InsertNode(t, 4);
	root = InsertNode(t, 10);
	root = InsertNode(t, 5);
	root = InsertNode(t, 17);
	root = InsertNode(t, 43);
	root = InsertNode(t, 49);
	root = InsertNode(t, 31);

	cout << "Duyet cay theo NLR: ";
	NLR(t);

	cout << "\nDuyet cay theo RLN: ";
	RLN(t);

	cout << "\nXoa 8, 11, 43, 6 ra khoi cay: ";
	Delete(t, 8);
	Delete(t, 11);
	Delete(t, 43);
	Delete(t, 6);
	cout << "\nBST sau khi xoa 4 node: ";
	NLR(t);

	cout << "\nCac node tren cay co duy nhat mot con: ";
	cout << OneChild(t) << " ";
}