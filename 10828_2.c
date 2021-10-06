#include <stdio.h>
#include <string.h>

int count = 0;
int stack[100001];


void empty()
{
	if (count == 0)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}

}

void size()
{
	printf("%d\n", count);
}

void push(int num)
{
	if (count > 100001)
	{
		printf("스택 포화 상태\n");
	}
	else
	{
		stack[count] = num;
		count++;
	}
}

void pop()
{
	if (count <= 0)
	{
		printf("-1\n");
	}
	else
	{
		count--;
		printf("%d\n", stack[count]);
		stack[count] = 0;
	}
}

void top()
{
	if (count <= 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", stack[count - 1]);
	}
}

int main()
{
	int input_num;
	char input_order[10];
	int push_num;

	scanf("%d", &input_num);
	int stack[10000];

	for (int i = 0; i < input_num; i++)
	{
		scanf("%s", input_order);
		if (!strcmp(input_order, "push"))
		{
			scanf("%d", &push_num);
			push(push_num);
		}
		else if (!strcmp(input_order, "pop"))
		{
			pop();
		}
		else if (!strcmp(input_order, "size"))
		{
			size();
		}
		else if (!strcmp(input_order, "empty"))
		{
			empty();
		}
		else if (!strcmp(input_order, "top"))
		{
			top();
		}
	}
}