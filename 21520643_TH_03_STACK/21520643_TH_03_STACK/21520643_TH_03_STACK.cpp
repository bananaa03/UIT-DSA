#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* pNext;
};

typedef struct node NODE;

struct stack
{
	NODE* pTop;
};

typedef struct stack STACK;

void Init(STACK& st)
{
	st.pTop = NULL;
}

NODE* CreateNode(int x)
{
	NODE* p = new NODE();
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}

int isEmpty(STACK st)
{
	if (st.pTop == NULL)
		return 1;
	return 0;
}

void Push(STACK& st, NODE* p)
{
	if (p != NULL)
	{
		if (isEmpty(st) == 1)
			st.pTop = p;
		else
		{
			p->pNext = st.pTop;
			st.pTop = p;
		}
	}
}

int Pop(STACK& st, int& x)
{
	if (isEmpty(st) == 0)
	{
		NODE* p = st.pTop;
		x = p->data;
		st.pTop = st.pTop->pNext;
		delete p;
		return x;
	}
}

