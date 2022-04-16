#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define FAULT 225
typedef struct variables
{
	unsigned char x;
	unsigned char y;


}variables;
unsigned char IsStackEmpty(unsigned char *top)
{
	if (*top == 0)
		return 1;
	else return 0;


}
unsigned char IsStackFull(unsigned char *top)
{
	if ((*top) >= MAX)
		return 1;
	else return 0;


}
void Push(variables *stack, unsigned char PushedValue_X, unsigned char PushedValue_Y, unsigned char *top)
{
	if (IsStackFull(top) == 0)
	{
		stack[*top].x = PushedValue_X;
		stack[*top].y = PushedValue_Y;
		(*top)++;
		
	}
	else
	{
		printf("Nu se mai poate executa algoritmul\n");
		exit(0);
	}
}
variables Pop(variables *stack, unsigned char*top)
{
	variables ValuesPoped;
	if (IsStackEmpty(top) == 0)
	{
		(*top) = (*top)--;
		ValuesPoped = stack[*(top)];
		stack[*top].x = 0;
		stack[*top].y = 0;

		return ValuesPoped;
	}
	
}
int main()
{
	variables stack[MAX] = {0}, ElementVectorTop,NewTop;
	unsigned char i, top = 0, x, y, TopValues_x, TopValues_y,NewX;
	printf("Introduceti valoarea variabilei X din functia Ackermann\n");
	scanf("%hhu", &x);

	printf("Introduceti valoarea variabilei Y din functia Ackermann\n");
	scanf("%hhu", &y);

	Push(stack, x, y, &top);

	do {
	
	ElementVectorTop = Pop(stack, &top);
	TopValues_x = ElementVectorTop.x;
	TopValues_y = ElementVectorTop.y;

		//printf("value x top=%hhu\n", TopValues_x);
		//printf("value y top=%hhu\n", TopValues_y);
		if (TopValues_x != 0 && TopValues_y != 0)
		{
			Push(stack, TopValues_x, TopValues_y, &top);
			Push(stack, TopValues_x, TopValues_y-1, &top);


		}
		if (TopValues_y == 0)
		{
			Push(stack, TopValues_x - 1, 1, &top);
		}
		
		if (TopValues_x == 0)
		{if (top== 0)
			{
				printf("Valoarea functiei Ackermann pentru valoarea introdusa este %hhu\n", TopValues_y + 1);
				return 0;
			}

			NewTop = Pop(stack, &top);
			NewX = NewTop.x;
			Push(stack, NewX-1, TopValues_y+1, &top);
			

		}

		for (i = (MAX - 1); i >= 0 && i <= MAX - 1; i--)
			printf("%hhu %hhu\n", stack[i].x, stack[i].y);
		printf("\n");
	}while (1);
		

	system("pause");
	return 0;
}
/*
if (TopValues_x == 0)
{
	if (top == 0)
	{
		printf("VAloare functiei Ackerman pentru valorile introduse este: %hhu", TopValues_y + 1);
		system("pause");
		exit(0);
	}
	else
	{
		top--;
		Push(stack, TopValues_x - 1, TopValues_y, &top);
	}

}
else if (TopValues_y == 0)

Push(stack, (TopValues_x - 1), 1, &top);
else
{
	Push(stack, TopValues_x, TopValues_y, &top);
	Push(stack, TopValues_x, TopValues_y - 1, &top);

}
*/