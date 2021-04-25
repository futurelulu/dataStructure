#include<stdio.h>
#include<string.h>
typedef int LDataType;
typedef struct listNode
{
	LDataType _data;
	struct listNode* _next;
}listNode;

typedef struct list
{
	listNode* _head;
}list;

listNode* creatNode(LDataType val)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

void listinit(list* lst)
{
	if (lst == NULL)
		return;
	lst->_head = NULL;
}

void listPushBack(list* lst,LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->_head == NULL)
	{
		lst->_head = creatNode(val);
	}
	else
	{
		listNode* tail = lst->_head;
		while (tail->_next != NULL)
			tail = tail->_next;
		tail->_next = creatNode(val);
	}
}

//删除 释放空间
//尾删 删除最后一个数据，更新上一个节点的next指向

void listPopBack(list* lst)
{
	if (lst == NULL||lst->_head == NULL)
		return;
	listNode* tail = lst->_head;
	listNode* prev = NULL;
	while (tail->_next != NULL)
	{
		prev = tail;
		tail = tail->_next;
	}
	free(tail);
	if (prev == NULL)//删除头结点
	{
		lst->_head == NULL;
	}
	else
		prev->_next = NULL;
}

void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->_head == NULL)
		lst->_head = creatNode(val);
	else
	{
		listNode* node = creatNode(val);
		node->_next = lst->_head;
		lst->_head= node;
	}
}

void listPopFront(list* lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	if (lst->_head->_next == NULL)
	{
		free(lst->_head);
		lst->_head = NULL;
	}
	else
	{
		listNode* node = lst->_head;
		lst->_head = lst->_head->_next;
		free(node);
	}
}
//插入在下一个位置
void listInsertAfter(listNode* cur, LDataType val)
{
	listNode* node = creatNode(val);
	listNode* next = cur->_next;
	cur->_next = node;
	node->_next = next;
}

//删除在下一个位置
void listEraseAfter(listNode* cur)
{
	listNode* next = cur->_next;
	if (next == NULL)
		return;
	listNode* nextnext = next->_next;
	free(next);
	cur->_next = nextnext;
}

listNode* listFind(list* lst, LDataType val)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* cur = lst->_head;
	while (cur)
	{
		if (cur->_data == val)
			return cur;
		else
			cur = cur->_next;
	}
	return NULL;
}

void listDestroy(list* lst)
{
	if (lst == NULL || lst->_head = NULL)
		return;
	listNode* cur = lst->_head;
	while (cur)
	{
		listNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	lst->_head = NULL;
}