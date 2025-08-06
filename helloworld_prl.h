#include <stdio.h>
#include <omp.h>

void fm_helloworld_prl()
{
#pragma omp parallel
	printf("hello world through prl header file\n");
}
