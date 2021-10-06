#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000001

typedef int element;

typedef struct
{
	element data[MAX_SIZE];
	int front, rear;
} DequeType;

void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

int empty(DequeType* q)
{
	return (q->rear == q->front);
}

int full(DequeType* q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

void push_front(DequeType* q, element item)
{
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
}

void push_back(DequeType* q, element item)
{
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

int size(DequeType* q)
{
	if (q->rear > q->front)
	{
		return q->rear - q->front;
	}
	else if (q->front > q->rear)
	{
		return MAX_SIZE-(q->front - q->rear);
	}
	else if (q->front == q->rear)
	{
		return 0;
	}
}

element pop_front(DequeType* q)
{
	if (empty(q) == TRUE)
	{
		return -1;
	}
	else
	{
		q->front = (q->front + 1) % MAX_SIZE;
		return q->data[q->front];
	}
}

element pop_back(DequeType* q)
{
	if (empty(q) == TRUE)
	{
		return -1;
	}
	else
	{
		int prev = q->rear;
		q->rear = (q->rear - 1+MAX_SIZE) % MAX_SIZE;
		return q->data[prev];
	}
}

element front(DequeType* q)
{
	if (empty(q) == TRUE)
	{
		return -1;
	}
	else return q->data[(q->front + 1) % MAX_SIZE];
}

element back(DequeType* q)
{
	if (empty(q) == TRUE)
	{
		return -1;
	}
	else return q->data[q->rear];
}


int main()
{
	int input_num;
	char input_order[15];
	int push_num;
	DequeType q;

	scanf_s("%d", &input_num);

	init_deque(&q);

	for (int i = 0; i < input_num; i++)
	{
		scanf_s("%s", input_order, sizeof(input_order));
		if (!strcmp(input_order, "push_front"))
		{
			scanf_s("%d", &push_num);
			push_front(&q, push_num);
		}
		else if (!strcmp(input_order, "push_back"))
		{
			scanf_s("%d", &push_num);
			push_back(&q, push_num);
		}
		else if (!strcmp(input_order, "pop_front"))
		{
			printf("%d\n", pop_front(&q));
		}
		else if (!strcmp(input_order, "pop_back"))
		{
			printf("%d\n", pop_back (&q));
		}
		else if (!strcmp(input_order, "size"))
		{
			printf("%d\n", size(&q));
		}
		else if (!strcmp(input_order, "empty"))
		{
			printf("%d\n", empty(&q));
		}
		else if (!strcmp(input_order, "front"))
		{
			printf("%d\n", front(&q));
		}
		else if (!strcmp(input_order, "back"))
		{
			printf("%d\n", back(&q));
		}
	}
}