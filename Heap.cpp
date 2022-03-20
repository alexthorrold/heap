#include <iostream>

struct MaxHeap
{
	int *a;
	int size;
	unsigned capacity;
};

MaxHeap *newMaxHeap(unsigned capacity)
{
	MaxHeap *h = (MaxHeap *)malloc(sizeof(MaxHeap));
	h->capacity = capacity;
	h->size = 0;
	h->a = (int *)malloc(capacity * sizeof(int));

	for (int i = 0; i < capacity; i++)
		h->a[i] = 0;
	
	return h;
}

//overflow handling
void insert(MaxHeap *h, int data)
{
	if (h->size == h->capacity)
	{
		std::cout << "Heap overflow";
		return;
	}

	int i = h->size + 1;

	h->a[i - 1] = data;

	while (i > 1)
	{
		if (h->a[i / 2 - 1] < data)
		{
			h->a[i - 1] = h->a[i / 2 - 1];
			h->a[i / 2 - 1] = data;
			i /= 2;
		}
		else
		{
			break;
		}
	}

	h->size++;
}

void heapDelete(MaxHeap *h, int data)
{

}

void print(MaxHeap *h)
{
	int power = 1;
	int add = 2;
	int newLineIndex = 0;

	for (int i = 0; i < h->size; i++)
	{
		printf("%d ", h->a[i]);

		if (i == newLineIndex)
		{
			std::cout << std::endl;

			newLineIndex += add;
			add *= 2;
		}
	}
}

void heapify(MaxHeap *h)
{
	for (int i = h->size - 1; i >= 0; i--)
	{

	}
}

int main()
{
	MaxHeap *h = newMaxHeap(100);

	//insert(h, 30);
	//insert(h, 20);
	//insert(h, 15);
	//insert(h, 5);
	//insert(h, 10);
	//insert(h, 12);
	//insert(h, 6);
	//insert(h, 40);
	//print(h);

	h->a[0] = 5;
	h->a[1] = 10;
	h->a[2] = 30;
	h->a[3] = 20;
	h->a[4] = 35;
	h->a[5] = 40;
	h->a[6] = 15;
	h->size = 7;
}
