#include<stdio.h>
#include<stdlib.h>

int i, k, j, n, v[10], m, sol = 0;
char isS, isV = 0;

void Init(int k)
{
	v[k] = 0;

}
int Succesor(k)
{
	if (v[k] < n)
	{
		v[k]++;
		return 1;
	}
	else
		return 0;
}
int valid(k)
{
	for (i = 1; i < k; i++)
		if (v[i] == v[k])
			return 0;
	return 1;

}
int solution(k)
{
	return (k == n);
}
void print()
{
	for (i = 1; i <= n; i++)
		printf("%d", v[i]);
	printf("\n");

}
void Backtracking()
{
	k = 1;
	Init(k);
	while (k > 0)
	{
		isS = 0; isV = 0;
		if (k <= n)//cat timp lista nu e vida
			do {
				isS = Succesor(k);//cauta succesor
				if (isS)
					isV = valid(k);

			} while (isS && !isV);

			if (isS)//este succesor si este valid
				if (solution(k))
					print();
				else {
					k++;
					Init(k);
				}
			else//nu am succesor ->cobor o pozitie in stiva
				k--;

	}
}
int main()
{

	n = 4; m = 4;
	Backtracking();
	return 0;
}

