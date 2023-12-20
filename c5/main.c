#include <stdio.h>
#include <stdlib.h>
#include "vectors\vector.h"
#include "matrix\matrix.h"

int main()
{
    const char *vecFile = "vectors\\example1.vec";
    const char *matFile = "matrix\\example1.mat";
    Vector vector = createVectorFromFile(vecFile);
    Matrix matrix = createMatrixFromFile(matFile);
    printf("Vector:\n");
    printVector(vector);
    printf("Matrix:\n");
    printMatrix(matrix);
    destroyVector(vector);
    destroyMatrix(matrix);
}