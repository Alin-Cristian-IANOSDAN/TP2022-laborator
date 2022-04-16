#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define FAULT 225
unsigned char IsStackEmpty(unsigned char *top)
{
	if (*top == 0)
		return 1;
	else return 0;


}
unsigned char IsStackFull(unsigned char *top)
{
	if (*top >=MAX)
		return 1;
	else return 0;


}
void Push(unsigned char *stack, unsigned char PushedValue, unsigned char *top)
{
	if (IsStackFull(top) == 0)
	{
		stack[(*top)] = PushedValue;
		(*top)++;
	}
	else
	{
		printf("Nu se mai poate executa algoritmul\n");
		exit(0);
	}
}
unsigned char Pop(unsigned char *stack, unsigned char*top)
{
	unsigned char ValuePoped;
	if (IsStackEmpty(top) == 0)
	{
		ValuePoped = stack[(*top)-1];
		(*top) = (*top)--;

		return ValuePoped;
	}
	else return FAULT;

}
int main()
{
	
	unsigned char stack[MAX] = {0};
	unsigned char GivenValue,ValueOnTop=0,y;
	unsigned char top = 0;
	printf("Introduceti valoarea pentru care sa se calculeze functia Manna Pnuelli\n");
	scanf("%hhu", &GivenValue);

	Push(stack, GivenValue, &top);
	Push(stack, 7, &top);
	
	
	for (;;)
	{
		
		ValueOnTop = Pop(stack, &top);
		if (ValueOnTop < 12)
		{
			Push(stack, ValueOnTop, &top);
			Push(stack, (ValueOnTop + 2), &top);
		}
		if (ValueOnTop >= 12)
		{
			//topul devine negativ daca ultimul element(VAlueOnTop) este cel poped din stiva
			if (IsStackEmpty(&top))
			{
				printf("Valoare Functiei Manna Punelli pentru valoarea introdusa este:%hhu", ValueOnTop-1);
				system("pause");
				return 0;
			}
			else
			{
				//top-ul trebuie sa coboare ca elemntul din urma celui eliminat sa devina x-1;
				top--;
				Push(stack, ValueOnTop - 1, &top);
				
				
			}
		}


	}

	return 0;
}