/**************************************************
*
* Matthew Page
* CSCS2330
* Discrete Structures
* 08/23/2016
*
* primebrute.c -    program to use brute force to
*                   calculate prime numbers.
*
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
    //struct for time management
	struct timeval time_start; // starting time
    struct timeval time_end;   // ending time

    //initialization of variables
	int max 	= 0; 
	int i 		= 2;  //outer loop counter
    int j       = 2;  //inner loop counter
    int primal  = 0;  //"is prime" flag, 0 for no, 1 for yes

    //convert command line argument from ASCII to integer
	max = atoi(argv[1]);

    //start timer
	gettimeofday(&time_start, 0);

    //main loop
	while (i <= max)
	{
        //printf("outer iteration: %d\n", i);
        while (j < i) 
        {
            //printf("inner iteration: %d\n", j);
            if ((i % j) == 0)
            {    
                primal = 1;
            }
            j++;
        }
        j = 2;

		if (primal == 0)
		{
			printf("%d ", i);
		}  
        primal = 0;
		i++;  	

	}
	
    //neatness...to make the children happy
	printf("\n");

	//end timer
	gettimeofday(&time_end, 0);

    //display runtime results
	fprintf(stderr, "%10.6lf\n", time_end.tv_sec - time_start.tv_sec + ((time_end.tv_usec - time_start.tv_usec) / 1000000.0));	


	exit (0);		
}
