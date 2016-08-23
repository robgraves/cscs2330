/**************************************************
*
* Matthew Page
* CSCS2330
* Discrete Structures
* 08/23/2016
*
* primebrute.c -    program to use a brute force to
*                   calculate prime numbers.
*
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
	struct timeval time_start; // starting time
    struct timeval time_end;   // ending time

	int max 	= 0; 
	int i 		= 2;
	float current = 0.0;

	float test = 0.0; 

	max = atoi(argv[1]);

	gettimeofday(&time_start, 0);

	test = (max / 3.0);	

	printf("%f", test);
	
	/*
	while (i < max)
	{
		current = (max % i);

		if (current == 0)
		{
			printf("%d ", i);
		}  
		i++;  	

	}
	*/

	printf("\n");
	
	gettimeofday(&time_end, 0);

	fprintf(stderr, "%10.6lf\n", time_end.tv_sec - time_start.tv_sec + ((time_end.tv_usec - time_start.tv_usec) / 1000000.0));	


	exit (0);		
}
