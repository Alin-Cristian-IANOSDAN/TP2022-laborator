#include<stdio.h>
#include<stdlib.h>

#define MAX_VALUE 8

int stiva[MAX_VALUE];
int top = -1;

int IsStackEmpty(int *top)
{
	if ((*top)<0)
		return 1;
	else return 0;

}
int IsStackFull(int *top)
{
	if ((*top)==MAX_VALUE)
		return 1;
	else return 0;


}
void Push(int*stiva, int *top, int valoare)
{
	if (IsStackFull(top)==0)
	{
		(*top)++;

		stiva[*top] = valoare;
		
	}
		
}
void Pop(int*stiva, int *top)
{
	int aux;
	if ((*top) == 0)
	{
		printf("Valoare functiei Manna Pnueli pentru valoare introdusa este:%d\n", stiva[*top]-1);
		exit(0);
	}

	if (IsStackEmpty(top) == 0)
	{
		aux = stiva[(*top)];
		stiva[(*top)] = 0;
		(*top)--;
		stiva[(*top)] = aux - 1;
		
	}
}
int main()
{
	int i;
	int aux;
	int valoare;

	printf("Introduceti valoarea pentru care sa se calculeze functia Manna Pnueli\n");
	scanf("%d", &valoare);

	//adaugare elemtul 1
	Push(stiva, &top,valoare);
	
	do {
		if (stiva[top] >= 12)
		{

			Pop(stiva, &top);

			for (i = 0; i < MAX_VALUE; i++)
				printf("%d ", stiva[i]);
			printf("\n");
		}


		if (stiva[top] < 12)
		{

			Push(stiva, &top, (stiva[top] + 2));

			for (i = 0; i < MAX_VALUE; i++)
				printf("%d ", stiva[i]);
			printf("\n");
		}
	} while (top >=0);

	system("pause");
	return 0;
}
