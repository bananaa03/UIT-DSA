#include <iostream>
#define MAX 11
using namespace std;

struct node
{
	int key;
	struct node* pNext;
};

typedef struct node HashTable[MAX];

