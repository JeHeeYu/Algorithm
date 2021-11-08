#include <stdio.h>
#include <stdlib.h>

typedef struct _Queue
{
	int* queue;
	int front, rear, capacity, num;
} Queue;

void InitQueue(Queue* q, int size);
void EnQueue(Queue* q, int data);
int DeQueue(Queue* q);
int Search(Queue* q, int data);
void Print(Queue* q);
void UnInitQueue(Queue* q);

int main()
{
	Queue q;

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
			printf("Queue Size Input : ");
			scanf("%d", &input);
			InitQueue(&q, input);
			break;

		case 2:
			printf("EnQueue Data : ");
			scanf("%d", &input);
			EnQueue(&q, input);
			break;

		case 3:
			printf("DeQueue Data : ");
			input = DeQueue(&q);
			if (input >= 1)
			{
				printf("%d\n", input);
			}
			break;

		case 4:
			printf("Search Data : ");
			scanf("%d", &input);
			index = Search(&q, input);
			if (index >= 1)
			{
				printf("q[%d] = %d\n", index, input);
			}
			else
			{
				printf("Search Error!\n");
			}
			break;

		case 5:
			printf("Queue Print!\n");
			Print(&q);
			break;
		}
	}
	UnInitQueue(&q);
	return 0;
}

void InitQueue(Queue* q, int size)
{
	q->queue = (int*)malloc(sizeof(int) * size);
	if (q->queue <= NULL)
	{
		printf("Queue Init Error!\n");
		return -1;
	}
	else
	{
		q->capacity = size;
		q->front = 0, q->rear = 0, q->num = 0;
	}
}

void EnQueue(Queue* q, int data)
{
	if ((q->rear + 1) % q->capacity == q->front)
	{
		printf("Queue is Full!\n");
		return -1;
	}
	else
	{
		q->rear = (q->rear + 1) % q->capacity;
		q->queue[q->rear] = data;
		q->num++;
	}
}

int DeQueue(Queue* q)
{
	if (q->front == q->rear)
	{
		printf("Queue is Empty!\n");
		return -1;
	}
	else
	{
		q->front = (q->front + 1) % q->capacity;
		return q->queue[q->front];
		q->num--;
	}
}

int Search(Queue* q, int data)
{
	int i;
	for (i = 0; i < q->capacity; i++)
	{
		if (q->queue[i] == data)
		{
			return i;
		}
	}
	return -1;
}

void Print(Queue* q)
{
	int i;
	for (i = 0; i < q->num; i++)
	{
		printf("q[%d] = %d\n", i, q->queue[i + 1]);
	}
}

void UnInitQueue(Queue* q)
{
	free(q->queue);
	q->front = q->rear = 0;
}
