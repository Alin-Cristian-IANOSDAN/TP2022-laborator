#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*1. Scrieti o functie recursiva care primeste ca paramentru un numar natural n si returneaza numarul obtinut din n prin eliminarea cifrelor impare. 
2. Se citeste un numar natural n (n<=20). Afisati un desen format din caracterul * ca in exemplul de mai jos. Se vor folosi exclusiv subprograme recursive. 
Exemplu: 
Pentru n=3 se afiseaza 
    * 
  *** 
***** 
  *** 
    * 
3. Se citeste un numar natural n. Sa se descompuna ca suma de puteri crescatoare ale lui 2. Se vor folosi doar prelucrari/calcule realizate cu ajutorul functiilor implementate recursiv. 
Exemplu: Pentru n=84 va afisa 4 16 64 (84 se descompune ca 4+16+64) 
4. Sa se scrie o functie recursiva care primeste trei parametri : n- numar natural; c 1 si c2 cifre si returneaza numarul obtinut din n prin inlocuirea tuturor aparitiilor cifrei c1 cu c2.
5. Sa se scrie un program recursive care sa rezolve expresia:
E=1+3+5+7+…..+(2n-1)*/


int Problema1(int n)
{
	int z;
	if ((n / 10) != 0)
		Problema1(n / 10);
	
	//!!!!Nu se pune else intrucat functia cand va iesi din apelul recursiv dinaintea ei nu va intra pe ramura lui
	
	z = n % 10;
	if ((z & 1) != 1)//daca numarul NU este impar-.conditie iesire
		printf("%d", z);
	
}
void Problema3(int n,int counter)
{
	int z;
	if ((n & 1) == 1)
		printf("%d\n", 1<<counter);
	//DE ce nu a mers cu pow?


	counter++;
	
	z=n/2;
	if(z!=0)
	Problema3(z,counter);


}
int Problema4(int n, int C1, int C2)
{

	//intr-un numar toate aparitiile cifrei C1 vor fi inlocuite cu C2

	if (n/10!= 0)
		 Problema4(n/10, C1, C2);
	if (n % 10 == C1)
		printf("%d", C2);
	else
		printf("%d", n % 10);
	

}
int Problema5(int n,int Sum)
{
	//Sum:(2n-1)

	if (n > 0) 
	{
		Sum = Sum + (2 * n - 1);
		return Problema5(n - 1, Sum);
	}
	return Sum;
}
int main()
{
	int Number;
	//Problema 1
	printf("Introduceti un numar natural\n");
	scanf("%d", &Number);
	Problema1(Number);
	

	//Problema 3
	printf("Introduceti un numar natural\n");
	scanf("%d", &Number);
	Problema3(84, 0);
	

	//Problema 4
	printf("Introduceti un numar natural\n");
	scanf("%d", &Number);
	Problema4(Number, 2, 5);
	
	//Problema 5
	printf("Introduceti un numar natural\n");
	scanf("%d", &Number);
	printf("Suma este %d\n",Problema5(4, 0));

	system("pause");
	return 0;
}
