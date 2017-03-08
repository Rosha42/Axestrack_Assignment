#include<stdlib.h>
#include <stdio.h>
#include<math.h>
int k=0;
int *bin(unsigned n)
{
    int *On_bit;
    unsigned i;
    int No_of_bits=log(n)*(1.44);
    int t=No_of_bits+1;
    On_bit = (int *)malloc(t*sizeof(int) );
    for (i = 1 << No_of_bits+1; i > 0; i = i / 2)
    {
        (n & i)? On_bit[k++]=t:1;
        t--;
    }
    return On_bit;
}
int main()
{
   int n;
   printf("Enter decimal form of number  to check \n");
   scanf("%d",&n);
   int *Ans= bin(abs(n));
   int i;
   printf("{");
   for(i=k-1;i>=0;i--)
   {
       printf("%d ",*(Ans+i));
   }
   printf("}");
   return 0;
}
