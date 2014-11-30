#include "RadixSorting.h"

#include <iostream>
using namespace std;
using std::cin;
using std::cout;
int main()
{
	/*测试理解用
	int a = sizeof(struct node);
	int b = sizeof(Node);
	List pa = (List)malloc(sizeof(struct node));//8byte，整个结构体的大小
	List pb = (List)malloc(sizeof(Node));//4byte,只分配了指针存放地址的大小

	pa->next = NULL;
	pb->next = NULL;

	free(pa);
	free(pb);//出错，分配了4字节大小的内存，要释放8字节大小
	*/

	int i;
	for (i=0; i<10; i++)
	{
		store[i] = (Node)malloc(sizeof(struct node));
		store[i]->data = 0;
		store[i]->next = NULL;
	}

	List head = CreatList();

	int input;
	Node node = head;
	while(cin>>input)
	{
		node->next = (Node)malloc(sizeof(struct node));
		node = node->next;
		node->data = input;
		node->next = NULL;
	}

	RadixSort(head);

	node = head->next;
	while(node != NULL)
	{
		cout<<node->data<<endl;
		node = node->next;
	}

	free(head);
	for (i=0; i<10; i++)
	{
		free(store[i]);
	}
	

	return 0;
}

List CreatList()
{
	List head = (List)malloc(sizeof(struct node));
	head->next = NULL;
	return head;
}



int GetDataNum(Node node, int count)
{
	int data = node->data;
	int x;

	switch(count)
	{
	case 1:
		x = data%10;
		break;
	case 2:
		x = data/10%10;
		break;
	case 3:
		x = data/10/10%10;
		break;
	}

	return x;
}

void RadixSort(List head)
{
	int x;
	Node node = NULL;
	Node stor = NULL;

	for (int i=1; i<=3; i++)
	{
		node = head->next;
		//将head中的数字放进对应的store中
		while(node != NULL)
		{
			x = GetDataNum(node, i);
			stor = store[x];
			while(stor->next != NULL)
			{
				stor = stor->next;
			}
			stor->next = (Node)malloc(sizeof(struct node));
			stor = stor->next;
			stor->data = node->data;
			stor->next = NULL;

			node = node->next;
		}

		node = head->next;
		//将排好序的store中的数字重新排成head
		for (int j=0; j<10; j++)
		{
			while(store[j]->next != NULL)
			{
				stor = store[j]->next;

				node->data = stor->data;
				node = node->next;

				store[j]->next = stor->next;
				stor->next = NULL;
				free(stor);
			}
		}

	}
}