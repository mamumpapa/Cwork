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
	int top;
} StackType;

void init_stack(StackType* s) 
{
	s->top = -1;
}

int empty(StackType* s) 
{
	return (s->top == -1);
}

int full(StackType* s) 
{
	return (s->top == (MAX_SIZE - 1));
}

void push(StackType* s, element item) 
{
	s->data[++(s->top)] = item;
}

int size(StackType* s)
{
	return s->top + 1;
}

element pop(StackType* s) 
{
	if (empty(s)==TRUE) 
	{
		return -1;
	}
	else return s->data[(s->top)--];
}

element top(StackType* s)
{
	if (empty(s)==TRUE) 
	{
		return -1;
	}
	else return s->data[s->top];
}


int main()
{
	int input_num;
	char input_order[10];
	int push_num;
	StackType s;

	scanf_s("%d", &input_num);

	init_stack(&s);

	for (int i = 0; i < input_num; i++)
	{
		scanf_s("%s", input_order, sizeof(input_order));
		if (!strcmp(input_order,"push"))
		{
			scanf_s("%d", &push_num);
			push(&s,push_num);
		}
		else if (!strcmp(input_order, "pop"))
		{
			printf("%d\n", pop(&s));
		}
		else if (!strcmp(input_order, "size"))
		{
			printf("%d\n",size(&s));
		}
		else if (!strcmp(input_order, "empty"))
		{
			printf("%d\n",empty(&s));
		}
		else if (!strcmp(input_order, "top"))
		{
			printf("%d\n",top(&s));
		}
	}
}