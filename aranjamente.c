#include<stdio.h>
#include<stdlib.h>
#define MAX 4
#define ARANJAMENTE 2
//sa se faca un program ce sa safiseze toate combinarile posibile
//

void creareMultime(int*multime)
{
	int index;
	//se dau elementele cu care sa se faca aranjamentele
	multime[0] = 0;
	for (index = 1; index <=MAX; index++)
	{
		printf("Introduceti elementul %d", index);
		scanf("%d", &multime[index]);
	}


}
void InitializeTop(int*stiva,int*elemente,int top,int *elementsTracker)
{
	(*elementsTracker) = 0;
	stiva[top] = elemente[(*elementsTracker)];

}
int Succesor(int*stiva,int*elemente, int top,int*elementsTracker)
{
	if ((*elementsTracker) < MAX)
	{
		//daca index-ul elementelor se mai poate incrementa, fara sa se depaseasca dimensiunea stivei
		(*elementsTracker)++;
		stiva[top] = elemente[(*elementsTracker)];
		return 1;
	}
	return 0;

}
int Validation(int*stiva, int top)
{
	int index;
	for (index = 1; index < top; index++)
		if (stiva[index] == stiva[top])
			return 0;
	return 1;
}
int isSolution(int top)
{
	return (top == ARANJAMENTE);
}
void PrintSolution(int*stiva)
{
	int index;
	for (index = 1; index <=ARANJAMENTE; index++)
		printf("%d", stiva[index]);
	printf("\n");
}

int main()
{
	int MultimeElemente[MAX];
	int stiva[10];
	int top = 1,elementsTracker=0;
	int isValid = 0,index;
	int isSuccesor=0;

	creareMultime(MultimeElemente);
	//backtrack
	InitializeTop(stiva,MultimeElemente, top, &elementsTracker);
	while (top > 0)
	{
		isValid=0 ; isSuccesor = 0;
		if(top<=ARANJAMENTE)
			do {
				isSuccesor = Succesor(stiva, MultimeElemente, top, &elementsTracker);
				if (isSuccesor)
					//daca este succesor,este valid?
					isValid = Validation(stiva, top);


			} while (isSuccesor && !isValid);//se repeta atata timp cat exista succesor,dar nu este valid

			//din bucla se poate iesi si CAND NU ESTE SUCCESOR

			if (isSuccesor)
			{
				if (isSolution(top))
				{
					PrintSolution(stiva);
					
				}
				else
				{
					top++;
					InitializeTop(stiva, MultimeElemente, top, &elementsTracker);
				}
			}
			else
			{
				top--;
				
					
				
					while (MultimeElemente[elementsTracker] != stiva[top])
					{
						elementsTracker--;
						
					}
				
				
				
			}
	}


	
	system("pause");
	return 0;
}