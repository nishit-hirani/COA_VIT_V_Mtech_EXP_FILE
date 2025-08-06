#include <stdio.h>
#include <omp.h>


double start_serial, end_serial;
double total_serial_time = 0;

double start_parallel, end_parallel;
double total_parallel_time = 0;

void fn_ret_tid_helloworld_srl()
{
	start_serial = omp_get_wtime();
	printf("This is counting time for serial\n");
	end_serial = omp_get_wtime();
	total_serial_time = end_serial - start_serial;
	printf("Total time for serial: %f\n", total_serial_time);
}
void fn_ret_tid_helloworld_prl()
{
	
	start_parallel = omp_get_wtime();
#pragma omp parallel
	printf("This is counting time for paralle\n");
	end_parallel = omp_get_wtime();
	double total_parallel_time = end_parallel - start_parallel;
	printf("Total time for parallel: %f\n", total_parallel_time);

	double speed_up = total_serial_time / total_parallel_time;

	double efficiency = (speed_up / 6) * 100;

	printf("speed up: %f\n", speed_up);
	printf("efficiency: %f\n", efficiency);
}
