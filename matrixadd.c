#include <stdio.h>
#include <stdlib.h>

typedef signed char sc;

int main(int argc, char **argv)
{
    FILE *in;
    FILE *out;

    sc **matrixA;
    sc **matrixB;
    sc **matrixC;

    int x;
    int y;

    if (argc < 3)
    {
            fprintf(stderr, "Error,: must provide at least 2 arguments\n");
            fprintf(stderr, "Usage:\n");
            fprintf(stderr, "\t%s matrix1file matrix2file [outputmatrixfile]\n", *(argv+0));

            exit(1);
    }

    return (0);
}
