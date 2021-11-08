#include <stdio.h>
#include <stdlib.h>

typedef struct _Satck
{
	int* stack;
	int top;
	int max;
} Stack;

void InitStack(Stack* s, int size);
void Push(Stack* s, int data);
int Pop(Stack* s);
int Search(Stack* s, int data);
void Print(Stack* s);
void UnInitStack(Stack* s);

int main()
{
	Stack s;
	while (1)
	{
		int input, index, i, num;

		printf("\n메뉴 입력\n");
		printf("1. Stack Init\n2. Push\n3. Pop\n4. Search\n5. Print\n0. Quit\nMenu Select : ");
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		switch (num)
		{
		case 1:
			printf("Stack Size Input : ");
			scanf("%d", &input);
			InitStack(&s, input);
			break;

		case 2:
			printf("Push Data : ");
			scanf("%d", &input);
			Push(&s, input);
			break;

		case 3:
			printf("Pop Data : ");
			index = Pop(&s);
			if (index >= 1)
			{
				printf("%d\n", index);
			}
			break;

		case 4:
			printf("Search Data : ");
			scanf("%d", &input);
			index = Search(&s, input);
			if (index >= 1)
			{
				printf("s[%d] = %d\n", index, input);
			}
			else
			{
				printf("Search Error!\n");
			}
			break;

		case 5:
			printf("Stack Print!\n");
			Print(&s);
			break;
		}
		UnInitStack(&s);
	}
	return 0;
}

void InitStack(Stack* s, int size)
{
	s->stack = (int*)malloc(sizeof(int) * size);
	if (s->stack <= NULL)
	{
		printf("Stack Init Error!\n");
		return -1;
	}
	else
	{
		s->top = 0;
		s->max = size;
	}

}

void Push(Stack* s, int data)
{
	if (s->top == s->max)
	{
		printf("Push Error!\n");
		return -1;
	}
	else
	{
		s->stack[s->top] = data;
		++s->top;
		return 0;
	}
}

int Pop(Stack* s)
{
	if (s->top <= 0)
	{
		printf("Pop Error!\n");
		return -1;
	}
	else
	{
		--s->top;
		return s->stack[s->top];
	}

}

int Search(Stack* s, int data)
{
	int i;
	for (i = 0; i < s->top; i++)
	{
		if (s->stack[i] == data)
		{
			return i;
		}
	}
	return -1;
}

void Print(Stack* s)
{
	int i;
	for (i = 0; i < s->top; i++)
	{

		printf("s[%d] = % d\n", i, s->stack[i]);
	}
}

void UnInitStack(Stack* s)
{
	free(s->stack);
	s->top = 0;
}
