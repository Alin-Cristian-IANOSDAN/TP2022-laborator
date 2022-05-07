/*LOGICA PROBLEMEI:
se va pozitiona cate o regina pe tabla
Daca pozitia este validata se trece la pozitionarea urmatoarei regine pe tabla(pe urmatoarea LINIE)
Se incrementeaza coloana pana cand se gaseste o pozitie corecta.
!!!!In momentul in care NU se mai poate incrementa valoarea, se va trece la regina anterioara

//daca s-au utilizat toate reginele, se va incrementa numarul de solutii

Cum se verifdica daca NU SE ATACA PE DIAGONALA?
se verifica secvebtial daca pentru casuta tabla[x][y] 

	ABS(i-xcoordinates[index])==ABS(y-yCoordinates[index]), unde indexul face trimitere catre index-ul reginei anterioare din vectorii x si y

	SE FOLOSESC 2 STIVE

	!!!!!!!!!Pentru problema particularizata cu n refine pt  tabla nXn, fiecare regina este pozitionata pe cate ub rand
*/



#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//tabla de 8 pe 8
#define N 8

void InitializeTop(int*stiva,int top)
{
	stiva[top] = 0;

}
int Succesor(int*stivaY, int top)
{
	//daca nu s-a cu regina pe ultima coloana(valoare din stivaY==N), se poate incrmenta
	if (stivaY[top] < N)
	{
		stivaY[top]++;
		return 1;
	}
	return 0;
}
int Validation(int*stivaX, int*stivaY, int top)
{
	
	int index;
	/*se verifica daca regina inserata se fala pe aceeasi coloana cu cele precedente*/
	for (index = 1; index <= (top - 1); index++)
		if (stivaY[top] == stivaY[index])
			return 0;

	/*se face verifica egalitatea ABS(i-xcoordinates[index])==ABS(y-yCoordinates[index]
	pentru toate elementele din cele doua stive de sub top*/
	for (index = 1; index <= (top - 1); index++)
		if ( abs(stivaX[top]-stivaX[index] ) != abs(stivaY[top]-stivaY[index]) )
			return 0;
	//daca nu e atacata nici pe diagonala si nici pe linie(conform algoritmului, reginele nu pot ajunge pe aceeasi coloane)
	return 1;
}
int IsSolution(int*stivaX,int top)
{
	//daca valoarea din top-ul stivei X este egala cu n, returneaza 1
	return (stivaX[top] == N);
	
}

int main()
{
	//vectorii in care vor fi strocate datele despre toate reginele DEJA pozitionate pe tabla
	//indicii vor porni de la 1 pentru simplitate
	int stivaX[N + 1];
	int stivaY[N + 1];
	int top = 1;
	int NumarPosibilitati = 0,isValid=0,isSuccesor=0;
	
	
	InitializeTop(stivaX, top);
	InitializeTop(stivaY, top);
	while (top!=0)//cat timp cele doua stive NU sunt nule
	{
		isValid = 0; isSuccesor = 0;
		
			do {
				isSuccesor = Succesor(stivaY, top);
				if (isSuccesor)
					//daca este succesor,este valid?
					isValid = Validation(stivaX,stivaY,top);


			} while (isSuccesor && !isValid);//se repeta atata timp cat exista succesor,dar nu este valid

			if (isSuccesor)
			{
				if (IsSolution(stivaX, top))
					NumarPosibilitati++;
				else
				{
					top++;
					InitializeTop(stivaX, top);
					InitializeTop(stivaY, top);
				}
			}
			else
			{
				InitializeTop(stivaX, top);
				InitializeTop(stivaY, top);
				top--;
			}


	}
	
	system("pause");
	return 0;
}
