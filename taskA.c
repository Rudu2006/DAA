#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float MinTemp(float Temp[], int n)
{
    float minT = Temp[0];

    for(int i = 0; i <= n-1; i++)
    {
        if(Temp[i] < minT)
        {
          minT = Temp[i];
        }
    }

    return minT;

}

float MaxPressure(float Pressure[], int n)
{
    float maxP = Pressure[0];

    for(int i = 0; i <= n-1; i++)
    {
        if(Pressure[i] < maxP)
        {
          maxP = Pressure[i];
        }
    }

    return maxP;

}


int main()
{
    int n = 100;
    float Temp[n], Pressure[n];
    float minT = -20, maxT = 50;
   float minP = 950, maxP = 1050;

    for(int i = 0; i <= n-1 ; i++)
    {
       Temp[i] = minT + ((float) rand() / RAND_MAX) * (maxT - minT );
       Pressure[i] = minP + ((float) rand() / RAND_MAX) * (maxP - minP);
    }

    clock_t start_time, end_time;
    double cpu_t_u;

    start_time = clock();

    minT = MinTemp(Temp, n);
    maxP = MaxPressure(Pressure, n);

    end_time = clock();

    printf("Minimum Temperature : %f\nMaximum Pressure : %f", minT, maxP);

    cpu_t_u = ((double)(end_time - start_time))/ CLOCKS_PER_SEC ;
    printf("\nCPU Time Consumed : %f", cpu_t_u);

    return 0;
}
