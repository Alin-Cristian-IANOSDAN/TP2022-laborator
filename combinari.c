

#include<stdio.h>
#include<stdlib.h>
#define MAX 4
#define COMBINARI 2
//sa se faca un program ce sa safiseze toate combinarile posibile


void creareMultime(int*multime)
{
	int index;
	//se dau elementele cu care sa se faca aranjamentele
	multime[0] = 0;
	for (index = 1; index <= MAX; index++)
	{
		printf("Introduceti elementul %d", index);
		scanf("%d", &multime[index]);
	}
}
void InitializeTop(int*stiva, int*elemente, int top, int *elementsTracker)
{
	(*elementsTracker) = 0;
	stiva[top] = elemente[(*elementsTracker)];

}
int Succesor(int*stiva, int*elemente, int top, int*elementsTracker)
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
	// daca se ajunge ca toate elementele stivei sa fie DIFERITE, se indeplineste prima conditie ca sa fie VALIDATE
		//ca un candidat sa fie VALIDAT,elementele trebuie sa fie SI in ordine crescatoare
		//daca elementele SUNT DIFERITTE , merita vazut daca sunt SI CRESCATOARE
	int index, GoNogo=1;
	for (index = 1; index < top; index++)
		if (stiva[index] == stiva[top])
		{
			GoNogo--;
			return GoNogo;

		}
	//daca se intalneste pe parcurs un ekement egal cu vf. stivei, GoNogo ajunge la 0 si va fi returnat;

	//inn caz ca ramane 1, se vereifica daca elementele sunt crescatoare

	for (index = 1; index <= top; index++)
		if (stiva[index] < stiva[index - 1])
		{
			GoNogo--;
			return GoNogo;

		}
	return GoNogo;
}


int isSolution(int*stiva, int top)
{
	//verificarea nu se pune in functia isSolution intrucat, in cazul in care nu este validata, va implica cresterea vf.stivei
	return (top == COMBINARI);
	
}
void PrintSolution(int*stiva)
{
	int index;
	for (index = 1; index <= COMBINARI; index++)
		printf("%d", stiva[index]);
	printf("\n");
}

int main()
{
	int MultimeElemente[MAX];
	int stiva[5];
	int top = 1, elementsTracker = 0;
	int isValid = 0, index;
	int isSuccesor = 0;

	stiva[0] = 0;
	creareMultime(MultimeElemente);
	//backtrack
	InitializeTop(stiva, MultimeElemente, top, &elementsTracker);
	while (top > 0)
	{
		isValid = 0; isSuccesor = 0;
		if (top <= COMBINARI)
			do {
				isSuccesor = Succesor(stiva, MultimeElemente, top, &elementsTracker);
				if (isSuccesor)
					//daca este succesor,este valid?
					isValid = Validation(stiva, top);


			} while (isSuccesor && !isValid);//se repeta atata timp cat exista succesor,dar nu este valid

			//din bucla se poate iesi si CAND NU ESTE SUCCESOR

			if (isSuccesor)
			{
				if (isSolution(stiva,top))
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