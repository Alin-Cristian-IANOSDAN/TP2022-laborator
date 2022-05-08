#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int SumaPrimelorN(int n)
{
	if (n == 0)//conditia de iesire
		return 0;
	else
		//formula de recurenta este:S(n)=n+S(n-1)
		//Se aplica SumaPrimelorN de n-1 pana cand se executa SumaPrimelorN(0) ce returneaza 0
	return n+SumaPrimelorN(n - 1) ;


}
int nFactorial(int n)
{

	if (n <= 1)//conditia de iesire
		return 1;
	else
		//form recurenta:n!=n*(n-1)!
		return n * nFactorial(n - 1);

}
int SumaCifrelor(int number)
{
	
	int suma=0;
	suma = number % 10;

	if (suma == 0)
		return 0;

	else
		return (suma + SumaCifrelor(number / 10));


}
int MannaPnuelli(int number)
{
	if (number >= 12)
		return number - 1;
	else
		return MannaPnuelli(number + 2);


}
int Fibonacci(int n)
{
	//Fibo: 1 2 3 5 8 13...
	//Index:1 2 3 4 5 6 ...
	if (n > 2)
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	else
		return n;
}
int InversareNumere(int raspuns,int n)
{
	//1234

	raspuns = (10 * raspuns + n % 10);
	if (n/10 == 0)
		return raspuns;
	else
		return InversareNumere(raspuns, n / 10);

}
int main()
{
	int n; int number;

	
	printf("introduceti indexul n\n");
	scanf("%d", &n);

	//Suma primelor n numere
	printf("Suma primelor %d numere este:->%d\n", n, SumaPrimelorN(n));
	
	//N factorial
	printf("Factorialul primelor %d numere este:->%d\n", n, nFactorial(n));

	//Suma cifrelor unui numar
	printf("Introduceti numarul la care sa se calculeze suma cifrelor\n");
	scanf("%d", &number);
	printf("Suma cifrelor numarului %d este:->%d\n", number, SumaCifrelor(number));
	
	//Functia Manna Pnuelli pentru un numar
	printf("Introduceti numarul la care sa se calculeze functia MannaPnuelli\n");
	scanf("%d", &number);
	printf("FUnctia MannaPnuelli pentru %d este:->%d\n", number, MannaPnuelli(number));
	

	//indexul unui numar din sirul lui fibonacci
	printf("Fibonacci de %d este->%d", n, Fibo(n));
	
	//inversarea unui numar
	printf("Introduceti numarul la care sa se inverseze cifrele\n");
	scanf("%d", &n);
	printf("Numarul %d inversat este %d", n, InversareNumere(0, n));

	
	system("pause");
	return 0;
}