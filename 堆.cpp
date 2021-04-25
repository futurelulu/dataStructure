typedef int HDataType;
typedef struct heap
{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

void heapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_size = hp->_capacity = 0;
}

void shiftDown(int* arr, int n, int curPos)
{
	int child = 2 * curPos + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		if (arr[curPos] > arr[child])
		{
			//swap(arr[curPos], arr[child]);
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;

			curPos = child;
			child = 2 * curPos + 1;
		}
		else
		{
			break;
		}
	}
	
}
//建堆，从最后一个非叶子节点进行向下调整的过程，向下调整的次数和非叶子节点的个数相同
//最后一个非叶子节点的位置(n-2)/2
void createHeap(int* arr, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(arr, n, i);
	}
}

//小堆
void shiftUp(int* arr, int n, int cur)
{
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		if (arr[cur] < arr[parent])
		{
			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;

			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}


void cheakCapacity(heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity);
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType) * hp->_capacity);
	}
}

//堆的插入，尾插，再向上调整
void heapPush(heap* hp, HDataType val)
{
	//检查容量
	cheakCapacity(hp);
	hp->_data[hp->_size++] = val;
	shiftUp(hp->_data, hp->_size, hp->_size - 1);

}


void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

}
//堆的删除
void heapPop(heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return 0;
	swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	hp->_size--;
	shiftDown(hp->_data, hp->_size, 0);
}

void PrintTopK(int* a, int n, int k)
{
	heap hp;
	heapInit(&hp);
	for (int i = 0; i < n; i++)
	{
		heapPush(&hp, a[i]);
	}
	while (k--)
	{
		printf("%d", heapTop（ & hp));
		heapPop(&hp);
	}
}
void test()
{
	int arr[] = { 20,17,4,16,5,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(arr, n, i);
	}
	//堆排序
	//end 待排序的元素个数，第一个已经拍好了
	int end = n - 1;
	while (end > 0)
	{
		swap(&arr[0], &arr[end]);
		shiftDown(arr, end, 0);
		--end;
	}

}