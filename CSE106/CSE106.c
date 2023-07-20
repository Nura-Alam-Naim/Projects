#include <stdio.h>
#include <time.h>
#include <limits.h>
// declaring global matrix to avoid segmentation fault
int vertices[10000][10000];

static int in_deg = 0, out_deg = 0;
// declaring unsigned variable to store the value of seed
static unsigned long int seed = 1;

int distinct() // generating the random number
{
    long long int a = 1664525;    // here a is the multiplier
    long long int c = 1013904223; // c is increment
    long long int m = 4294967296; // m is modulus
    // calculating the next random number
    seed = ((a * seed) + c) % m;
    // ensuring that the value fits in the variable
    return (seed / 65536) % ULONG_MAX;
}

void getData(int ver) // storing
{
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            vertices[i][j] = (distinct() % 2);
        }
    }
}
void calc_Degree(int ver)
{
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            out_deg += vertices[i][j]; // calculating out degree
            in_deg += vertices[j][i];  // calculaitng in degree
        }
    }
}
int main()
{
    int ver;
    scanf("%d", &ver); // Initializing two variables to store clock time

    clock_t initial, end;
    double calc_time;

    seed = time(NULL); // Generating a seed for our linear congruential algorithm.
                       // Here time function return the time in sec calculated from 1970

    initial = clock(); // initializing the time for our claculation

    getData(ver);

    calc_Degree(ver); // Here calculating the in and out degree of the matrix

    printf("\nTotal In Degree: %d\n", in_deg);
    printf("Total Out Degree: %d\n", out_deg);
    if (in_deg == out_deg)
    {
        printf("\nTotal In Degree and Total Out Degree is Equal\n");
    }
    else
    {
        printf("\nTotal In Degree and Total Out Degree is not Equal\n");
    }

    end = clock(); // tracing the ending time

    // Then converting second into ms by multiplying 1000
    calc_time = ((double)(end - initial)) / ((double)CLOCKS_PER_SEC) * 1000;
    // here CLOCK_PER_SEC is used to convert the time into seconds
    printf("\nComputational time: = %.0lf ms\n", calc_time);
    return 0;
}
