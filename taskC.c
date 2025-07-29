#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int LinearSearch(float Temp[], int size)
{
   int FirstOcc, flag = 0;

   for(int i = 0; i < size; i++)
   {
      if(Temp[i]>=30)
      {
         flag = 1;
         FirstOcc = i;
         break;
      }
   }

   if(flag == 1)
   {
      return FirstOcc;
   }

   return -1;
}

int BinarySearch(float Temp[], int n, int target)
{
   int left = 0;
   int right = n-1;
   int FirstOcc = -1;

   while(left<=right)
   {
      int mid = left + (right - left)/2 ;

      if(Temp[mid] == target)
      {
         FirstOcc = mid;
         break;
      }
      else if(Temp[mid] < target)
      {
         left = mid + 1;
      }
      else 
      {
         right = mid - 1;
      }
   }

   return FirstOcc;
}



int main()
{
   int n = 100;
    float Temp[n];
    float minT = 20, maxT = 50;
    int FirstOcc;
    clock_t start_time, end_time;
    double cpu_t_u;

    for(int i = 0; i <= n-1 ; i++)
    {
       Temp[i] = minT + ((float) rand() / RAND_MAX) * (maxT - minT );
    }

    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (Temp[j] < Temp[min_idx]) {
                min_idx = j;
            }
        }
        temp = Temp[min_idx];
        Temp[min_idx] = Temp[i];
        Temp[i] = temp;
    }

     start_time = clock();

    FirstOcc = LinearSearch(Temp, n);

    printf("For n = %d", n);
    printf("\nLinear Search : ");
   if(FirstOcc != -1)
   {
       printf("\nFirst Occurrence of temperature >=30 is at index : %d", FirstOcc);
   }

   else
   {
        printf("\nNo Temperature >= 30");
   }

    end_time = clock();
    cpu_t_u = ((double)(end_time - start_time))/ CLOCKS_PER_SEC ;
    printf("\nCPU Time Consumed in Linear Search : %f", cpu_t_u);

    start_time = clock();

    FirstOcc = BinarySearch(Temp, n, 30);

    printf("\nBinary Search : ");
   if(FirstOcc != -1)
   {
       printf("\nFirst Occurrence of temperature >=30 is at index : %d", FirstOcc);
   }

   else
   {
        printf("\nNo Temperature >= 30");
   }

    end_time = clock();
    cpu_t_u = ((double)(end_time - start_time))/ CLOCKS_PER_SEC ;
    printf("\nCPU Time Consumed in Binary Search : %f", cpu_t_u);




}

   
    

   