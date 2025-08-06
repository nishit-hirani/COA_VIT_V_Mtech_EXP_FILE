#include <stdio.h>
#include <omp.h>
void fn_wsc_for_2constructs()
{
	int i;
#pragma omp parallel
	{
	printf("thread id: %d work sharing starts\n",omp_get_thread_num());
#pragma omp for
	for (i = 0;i < 24;i++)
			printf("hello world in iteration: %d by tid: %d\n", i, omp_get_thread_num());
		
	}
}
void fn_wsc_for_1construct()
{
	printf("\n\n");
	int i;
#pragma omp parallel for
	for (i = 0;i < 24;i++)
	{
		printf("hello world in iteration : %d by tid : %d\n", i, omp_get_thread_num());
	}
}
