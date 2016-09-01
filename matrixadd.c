#include <stdio.h>
#include <stdlib.h>

typedef signed char sc;

int main(int argc, char **argv)
{
	FILE  *in;
	FILE  *out;

	sc   **matrixA;
	sc   **matrixB;
	sc   **matrixC;	// result matrix

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
			fscanf(in, "%hhd", (*(matrixA+x)+y));
		}
	}

	fclose(in);

	// second matrix
	in = fopen(*(argv+2), "r");
	if (in == NULL)
	{
		fprintf(stderr, "Error: Couldn't open '%s' for read!\n", *(argv+2));
		exit(1);
	}

	fscanf(in, "%hhd", &r2);
	fscanf(in, "%hhd", &c2);

	matrixB = (sc **) calloc(r2, sizeof(sc *));
	for (x = 0; x < r2; x++)
	{
		*(matrixB+x) = (sc *) calloc(c2, sizeof(sc));
		for (y = 0; y < c2; y++)
		{
			fscanf(in, "%hhd", (*(matrixB+x)+y));
		}
	}

	fclose(in);

	// display matrixA
	fprintf(stdout, "matrixA:\n");
	for (x = 0; x < r1; x++)
	{
		fprintf(stdout, "| ");
		for (y = 0; y < c1; y++)
		{
			fprintf(stdout, "%3hhd ", *(*(matrixA+x)+y));
		}
		fprintf(stdout, "|\n");
	}
	fprintf(stdout, "\n");

	// display matrixB
	fprintf(stdout, "matrixB:\n");
	for (x = 0; x < r2; x++)
	{
		fprintf(stdout, "| ");
		for (y = 0; y < c2; y++)
		{
			fprintf(stdout, "%3hhd ", *(*(matrixB+x)+y));
		}
		fprintf(stdout, "|\n");
	}
	fprintf(stdout, "\n");

	fprintf(stdout, "Initiating matrix coherence analysis ... ");
	if ((r1 == r2) && (c1 == c2))
		fprintf(stdout, "SUCCESS!\n");
	else
	{
		fprintf(stdout, "MATTER STREAMS MISALIGNED!\n");
		exit(1);
	}

	// actual matrix addition operation


	// display resultant matrix (and save it to the file result.data)


	return(0);
}
