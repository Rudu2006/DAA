#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Task-B: Naive Pairwise Comparison Approach

float MinTemp(float Temp[], int n)
{
    float minT = Temp[0];
    int flag1 = 0;

    for(int i = 0; i <= n-1; i++)
    {
         flag1 = 1; 

        for(int j = (i+1) ; j <= n-1 ; j++)
        {
        
          if(Temp[i] < Temp[j])
          {
             minT = Temp[i];
          }
          else
          {
             flag1 = 0;
          }

          if(flag1 == 0)
          {
            break;
          }
           
        
        }
        
    }

    return minT;

}

float MaxPressure(float Pressure[], int n)
{
    float maxP = Pressure[0];
    int flag1 = 1;

    for(int i = 0; i <= n-1; i++)
    {
        for(int j = (i+1) ; j <= n-1 ; j++)
        {
        
          if(Pressure[i] > Pressure[j])
          {
             maxP = Pressure[i];
          }
          else
          {
             flag1 = 0;
          }

          if(flag1 == 0)
          {
            break;
          }
           
        
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

    end_time = clock();

    printf("Minimum Temperature : %f", minT);
    cpu_t_u = ((double)(end_time - start_time))/ CLOCKS_PER_SEC ;
    printf("\nCPU Time Consumed for Estimating Minimum Temperature : %f", cpu_t_u);

    start_time = clock();

    maxP = MaxPressure(Pressure, n);

    end_time = clock();

    printf("\nMaximum Pressure : %f", maxP);

    cpu_t_u = ((double)(end_time - start_time))/ CLOCKS_PER_SEC ;
    printf("\nCPU Time Consumed for Estimating Maximum Pressure : %f", cpu_t_u);

    return 0;
}
