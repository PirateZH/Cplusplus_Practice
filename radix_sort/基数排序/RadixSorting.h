#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
	int data;
	node *next;
}*ptrNode;


typedef ptrNode List;
typedef ptrNode Node;

Node store[10];

List CreatList();//创建链表表头
int GetDataNum(Node node, int count);//获得每一位的数字
void RadixSort(List head);//排序