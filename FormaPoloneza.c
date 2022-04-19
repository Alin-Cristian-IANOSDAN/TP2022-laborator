#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 30
#define FAULT 225



unsigned char IsStackEmpty(unsigned char top)
{
	if (top == 0)
		return 1;
	else return 0;

}
unsigned char IsStackFull(unsigned char top)
{
	if (top == MAX)
		return 1;
	else return 0;

}
void Push(unsigned char*stiva,unsigned char ValoarePushed,unsigned char*top)
{
	if (IsStackFull((*top)) == 0)
	{
		stiva[(*top)] = ValoarePushed;
		(*top)++;


	}
	else
		printf("!!stack overflow!!!\n");

}
unsigned char Pop(unsigned char*stiva, unsigned char*top)
{
	unsigned char ValoarePoped;
	if (IsStackEmpty(*top) == 0)
	{
		(*top)--;
		ValoarePoped = stiva[*top];
		stiva[*top] = 0;
		return ValoarePoped;
	}
	else return FAULT;

}
unsigned char Priority(unsigned char character)
{
	unsigned char priority;
	if ((character == '+') |( character == '-'))
		priority = 3;
	else if ((character == '*' )|( character == '/'))
		priority = 2;

	else if ((character == '(') |( character == ')'))
		priority = 1;
	else
		priority = 0;
	return priority;
}
void EraseElementFromArray(unsigned char*array)
{
	int index;
	int pickup;

	for (index = 0; index < strlen(array); index++)
	{
		if (array[index] == ')')
			for (pickup = index; pickup < strlen(array); pickup++)
			{
				array[pickup] = array[pickup + 1];
			}
	}
	
}
void Polishform(unsigned char*ExpressionVector,unsigned char*stiva, unsigned char*top1, unsigned char*fp, unsigned char*top2)
{
	unsigned char j,index,z=0;
	for (index = 0; ExpressionVector[index]!= 0; index++)
	{
		if (Priority(ExpressionVector[index]) == 0)
			Push(fp, ExpressionVector[index],top2);
		if ((Priority(ExpressionVector[index]) == 1) | (Priority(ExpressionVector[index]) == 2))
			Push(stiva,ExpressionVector[index],top1);

		if (Priority(ExpressionVector[index]) == 3)
		{
			
			while (stiva[(*top1) - 1] != '(')
			{
				Push(fp, Pop(stiva, top1), top2);
				
			}
			Push(stiva, ExpressionVector[index], top1);
		}
		
		if (ExpressionVector[index] == ')')
		{
			while (stiva[(*top1) - 1] != '(')
			{
				Push(fp, Pop(stiva, top1), top2);
				
			}
			z = Pop(stiva, top1);
			
			if ((*top1) == 0)
			printf("Forma poloneza pentru expresia introdusa a fost gasita\n");
			

		}
		
	}
	EraseElementFromArray(fp);
	for (index = 0; index < MAX; index++)
	{
		printf("%c", fp[index]);

	}
	
}
int main()
{

	unsigned char stiva[MAX] = { 0 };
	unsigned char fp[MAX]={0};
	unsigned char top1 = 0,top2=0;
	unsigned char ExpressionVector[30] ;
	int index;
	printf("Introduceti expresia pentru care sa se faca forma poloneza-\n !!Introduceti paranteze la inceput si sfarsit!!\n");
	scanf("%s", ExpressionVector);
	
	Polishform(ExpressionVector,stiva, &top1, fp, &top2);
	
	return 0;
}
