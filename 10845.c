#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100001

typedef int element;

typedef struct
{
	element data[MAX_SIZE];
	int front, rear;
} QueueType;

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int empty(QueueType* q)
{
	return (q->rear == q->front);
}

int full(QueueType* q)
{
	return (q->rear == (MAX_SIZE - 1));
}

void push(QueueType* q, element item)
{
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

int size(QueueType* q)
{
	return ((q->rear - q->front) + MAX_SIZE) % MAX_SIZE;
}

element pop(QueueType* q)
{
	if (empty(q)==TRUE)
	{
		return -1;
	}
	else
	{
		q->front = (q->front + 1) % MAX_SIZE;
		return q->data[q->front];
	}
}

element front(QueueType* q)
{
	if (empty(q) == TRUE)
	{
		return -1;
	}
	else return q->data[(q->front + 1) % MAX_SIZE];
}

element back(QueueType* q)
{
	if (empty(q) == TRUE)
	{
		return -1;
	}
	else return q->data[(q->rear) % MAX_SIZE];
}


int main()
{
	int input_num;
	char input_order[10];
	int push_num;
	QueueType q;

	scanf_s("%d", &input_num);

	init_queue(&q);

	for (int i = 0; i < input_num; i++)
	{
		scanf_s("%s", input_order, sizeof(input_order));
		if (!strcmp(input_order,"push"))
		{
			scanf_s("%d", &push_num);
			push(&q,push_num);
		}
		else if (!strcmp(input_order, "pop"))
		{
			printf("%d\n", pop(&q));
		}
		else if (!strcmp(input_order, "size"))
		{
			printf("%d\n",size(&q));
		}
		else if (!strcmp(input_order, "empty"))
		{
			printf("%d\n",empty(&q));
		}
		else if (!strcmp(input_order, "front"))
		{
			printf("%d\n",front(&q));
		}
		else if (!strcmp(input_order, "back"))
		{
			printf("%d\n", back(&q));
		}
	}
}