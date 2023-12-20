// evol.c
// ELEC1201 Lab C3: Operators and Arrays
// Evolutionary Computing
// KPZ 2018, MIT License
//
// Compile with math library:
//    gcc evol.c -lm -o evol

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define EQUATION y = pow((x - 3), 2)
#define Y_TARGET 0.0
#define EPSILON 0.0001

#define POP_SIZE 100
#define MAX_GEN 100

#define MUTATION_STRENGTH 0.5
#define RND_INIT 9

void printheader(void);
float rnd(); // Random values 0.0 to 1.0
void initpop(float *pop, int size);
void offspring(float parent, float mutst, float *pop, int size);
void hungry(int size, float *pop);

int main()
{
    float population[POP_SIZE];
    int gen = 0;
    float best_ifit = FLT_MAX; // worst possible
    float fit = 1 / best_ifit;
    float best;
    float x, y;
    float ifit; // inverse fitness
    int i;

    // printheader();
    // srand(RND_INIT);
    // initpop(population, POP_SIZE);

    for (int j = 21; j < 31; j++)
    {
        srand(j);
        initpop(population, POP_SIZE);
        gen = 0;
        best_ifit = FLT_MAX;
        fit = 1 / best_ifit;

        while (fabs(best_ifit) > EPSILON + Y_TARGET && gen < MAX_GEN)
        {

            for (i = 0; i < POP_SIZE; i++)
            {

                x = population[i];

                EQUATION; // y = f(x)

                ifit = fabs(y - Y_TARGET);

                // printf("x= %f  =>  y=  %+f,    ifit = %f\n", x, y, ifit);

                // Is there a better one?
                if (ifit < best_ifit)
                {
                    best_ifit = ifit;
                    best = x;
                    fit = best_ifit == EPSILON + Y_TARGET ? -1 : 1 / best_ifit;
                }
            }
            x = best;
            EQUATION; // y = f(x)

            // printf("Generation %4d with best solution:  x= %f --> f(x)= %f\n\n",
            //        gen++, best, y);
            printf("%d, %f\n", gen++, fit);

            offspring(best, MUTATION_STRENGTH, population, POP_SIZE);
        }
        printf("----------------------------\n");
    }
}

void printheader()
{
    printf("\n\n");
    printf("###############\n");
    printf("## Evolution ##\n");
    printf("###############\n");
}

// Returns a random value between 0.0 and 1.0
float rnd()
{
    return rand() / (float)RAND_MAX;
}

void initpop(float *pop, int size)
{
    for (int i = 0; i < size; i++)
    {
        pop[i] = rnd();
    }
}

void offspring(float parent, float mutst, float *pop, int size)
{
    float temp = -1;
    pop[0] = parent;
    for (int i = 1; i < size; i++)
    {

        temp = parent + (2 * rnd() - 1) * mutst;
        while (temp < 0.0 && temp > 1.0)
        {
            temp = parent + (2 * rnd() - 1) * mutst;
        }

        pop[i] = temp;
    }
}

void hungry(int size, float *pop)
{
    int a = rnd() * (size - 1);
    int b = rnd() * (size - 1);
    int c = rnd() * (size - 1);
    float A = pop[a];
    float B = pop[b];
    float C = pop[c];
    float AB = fabs(A - B);
    float BC = fabs(B - c);
    float AC = fabs(A - C);
    float Winner;
    if (AB + AC > AB + BC && AB + AC > BC + AC)
    {
        Winner = A;
    }
    else if (AB + BC > BC + AC)
    {
        Winner = B;
    }
    else
    {
        Winner = C;
    }
    // call offspring() in the main but the size of the population will be small about 5
}