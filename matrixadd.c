#include <stdio.h>
#include <stdlib.h>

typedef signed char sc;

int main(int argc, char **argv)
{
	FILE  *in;
	FILE  *out;

	sc   **matrixA;
	sc   **matrixB;
	sc   **matrixC;

	sc    x;
	sc    y;
	sc    r1, r2;
	sc    c1, c2;

	if (argc <  3)
	{
		fprintf(stderr, "Error: must provide at least 2 arguments\n");
		fprintf(stderr, "Usage:\n");
		fprintf(stderr, "\t%s matrix1file matrix2file [outputmatrixfile]\n", *(argv+0));
		exit(1);
	}

	in = fopen(*(argv+1), "r");
	if (in == NULL)
	{
		fprintf(stderr, "Error: Couldn't open '%s' for read!\n", *(argv+1));
		exit(1);
	}

	fscanf(in, "%hhd", &r1);
	fscanf(in, "%hhd", &c1);

	matrixA = (sc **) calloc(r1, sizeof(sc *));
	for (x = 0; x < r1; x++)
	{
		*(matrixA+x) = (sc *) calloc(c1, sizeof(sc));
		for (y = 0; y < c1; y++)
		{
			fscanf(in, "%hhd", *(*(matrixA+y)+x));
		}
	}

	fclose(in);

	return(0);
}
