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

List CreatList();//���������ͷ
int GetDataNum(Node node, int count);//���ÿһλ������
void RadixSort(List head);//����