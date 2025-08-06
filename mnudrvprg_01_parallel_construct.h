#include <stdio.h>
#include "helloworld_srl.h"
#include "helloworld_prl.h"
#include <cstdlib>

int fn_mnudrv_010_parallel_construct()
{
	int choice;
	while (1)
	{

		printf("\nList of Choices\n\n");

		printf("Enter 0 to exit\n");
		printf("Enter 1 for serial\n");
		printf("Enter 2 for serial\n\n");

		printf("Enter your choice\n");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 0:
			printf("you opted to exit program");
			exit(0);
			break;
		case 1:
			printf("This is output of hello world serial program\n");
			fm_helloworld();
			break;
		case 2:
			printf("This is output of hello world parallel program\n");
			fm_helloworld_prl();
			break;
		default:
			printf("wrong choice\n");
		}
	}
	return 0;
}
