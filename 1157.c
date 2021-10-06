#include <stdio.h>
#include <string.h>


int main()
{
	int ascii_num[1000001] = { 0, };
	char input[1000001];
	int cnt_arr[127] = { 0, };
	int max = cnt_arr[0];
	int index = 0;
	int q = 0;
	int i = 0;

	scanf_s("%s", input,sizeof(input));

	int len = strlen(input);

	for (int i = 0; i < len; i++)
	{
		ascii_num[i] = input[i];
	}
	for (int i = 0; i < len; i++)
	{
		if (ascii_num[i] > 96 && ascii_num[i] < 123)
		{
			ascii_num[i] -= 32;
		}
		cnt_arr[ascii_num[i]] += 1;
	}
	while (i < 127)
	{
		if (max < cnt_arr[i])
		{
			max = cnt_arr[i];
			index = i;
			if (q>0)
			{
				q=0;
			}
		}
		i++;
		if (max == cnt_arr[i] && cnt_arr[i]!=0)
		{
			q++;
		}
	}
	if (q == 0)
	{
		printf("%c\n", index);
	}
	else if (q > 0)
	{
		printf("?\n");
	}

	return 0;
}