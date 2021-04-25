typedef int QDataType;
typedef struct QNode
{
	struct QNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;
	QNode* _tail;
}Queue;

QNode* creatNode(QDataType val)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

void queueInit(Queue* q)
{
	q->_front = q->_tail = NULL;
}
void queuePush(Queue* q,QDataType val)
{
	QNode* node = creatNode(val);
	if (q->_front == NULL)
		q->_front = q->_tail = node;
	else
	{
		q->_tail->_next = node;
		q->_tail = node;
	}
	
}
void queuePop(Queue* q)
{
	if(q->_front)
	{
		
		QNode* next = q->_front->_next;
		QNode* dNode = q->_front;
		free(dNode);
		q->_front = next;
		if (q->_front == NULL)
			q->_tail == NULL;
	}
}
QDataType queueFront(Queue* q)
{
	return q->_front->_data;
}


QDataType queueBack(Queue* q)
{
	return q->_tail->_data;
}

int queueSize(Queue* q)
{
	int num = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		++num;
		cur = cur->_next;
	}
	return num;
}
int queueEmpty(Queue* q)
{
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}
void queueDestory(Queue* q)
{
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}


void test()
{
	Queue q;
	queueInit(q);
	queuePush(&q, 1);
	while (queueEmpty(&q) != 1)
	{
		queueFront(&q);
		queuePop(&q);
	}
}