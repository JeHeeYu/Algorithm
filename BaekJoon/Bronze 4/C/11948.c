#include <stdio.h>

int main()
{   
   int arr[6];
   int i, max = 0, sum = 0, min = 101;

   for(i = 0; i < 6; i++)
      scanf("%d", &arr[i]);
      
   for(i = 0; i <4; i++)
   {
      sum += arr[i];
      if(arr[i] < min)
         min = arr[i];
   }
   sum -= min;
   

   for(i = 4; i < 6; i++)
   {
      if(arr[i] > max)
         max = arr[i];
   }
   sum += max;
   
   printf("%d", sum);
}
