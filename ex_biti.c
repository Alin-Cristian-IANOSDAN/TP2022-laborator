
#include<stdio.h>
#include<stdlib.h>
#define NO_USERS 5

enum ListOfRights {
	E_READ = 1,
	E_WRITE = 2,
	E_DELETE = 4,
	E_RENAME = 8,
	E_COPY = 16
};

void AddRights(unsigned char *users, unsigned short int WhichUser)
{
	printf("\nFor user %d\n", WhichUser);
	unsigned short int  CheckAnswear;

	printf("READ?\n");
	scanf("%hu", &CheckAnswear);
	if(CheckAnswear==1)
		users[WhichUser] = (users[WhichUser] | E_READ);

	printf("WRITE\n");
	scanf("%hu", &CheckAnswear);
    if (CheckAnswear == 1)
		users[WhichUser] = (users[WhichUser] | E_WRITE);

	printf("DELETE?\n");
	scanf("%hu", &CheckAnswear);
	if (CheckAnswear == 1)
		users[WhichUser] = (users[WhichUser] | E_DELETE);

	printf("REBAME?\n");
	scanf("%hu", &CheckAnswear);
	if (CheckAnswear == 1)
		users[WhichUser] = (users[WhichUser] | E_RENAME);

	printf("COPY?\n");
	scanf("%hu", &CheckAnswear);
	if (CheckAnswear == 1)
	users[WhichUser] = (users[WhichUser] | E_COPY);

}
void ReturnRights(unsigned char *users, unsigned short int WhichUser)
{
	
	if (users[WhichUser] == 0)
		printf("Userul nu are drepturi in aplicatie\n");
	else {
		printf("Userul %d are urmatoarele drepturi:",WhichUser);
		
		if ((users[WhichUser] & 1) != 0)
			printf("Read, ");
		if ((users[WhichUser] & 2) != 0)
			printf("Write, ");
		if ((users[WhichUser] & 4) != 0)
			printf("Delete, ");
		if ((users[WhichUser] & 8) != 0)
			printf("Rename, ");
		if ((users[WhichUser] & 16) != 0)
			printf("Copy, ");
		printf(".\n");
	}

}
int main()
{
	unsigned char users[NO_USERS] = {0};
	unsigned short int index;
	
		printf("Carui user doriti sa asignati drepturi?\n");
		scanf("%hu", &index);
		if(index>=0&&index<NO_USERS)
			AddRights(&users, index);

		printf("%d", users[index]);
		ReturnRights(&users, index);
	
	system("pause");
	return 0;
}