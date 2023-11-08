#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* pNext;
};

typedef struct node NODE;

struct queue
{
	NODE* pHead;
	NODE* pTail;
};

typedef struct queue QUEUE;

void Init(QUEUE& que)
{
	que.pHead == NULL;
	que.pTail = NULL;
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

int isEmpty(QUEUE que)
{
	if (que.pHead == NULL)
		return 1;
	return 0;
}

void EnQueue(QUEUE& que, NODE* p)
{
	if (isEmpty(que) == NULL)
		que.pHead = que.pTail = p;
	else
	{
		que.pTail->pNext = p;
		que.pTail = p;
	}
}

int DeQueue(QUEUE& que, int& x)
{
	if (isEmpty(que) == 0)
	{
		NODE* p = que.pHead;
		x = p->data;
		que.pHead = que.pHead->pNext;
		delete p;
	}
	if (que.pHead == NULL)
		que.pTail == NULL;
	return x;
}