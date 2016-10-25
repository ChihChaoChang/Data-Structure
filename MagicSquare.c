/*****************************
   hw01: 魔方陣
   姓名: 張智超
   學號: 
******************************/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void magic(int);

int main(void)
{
   magic(1);
   magic(3);
   magic(5);
   magic(7);
   magic(9);
}//end main()


void magic(int n)
{

   int a[SIZE][SIZE] = {0};
   int i=0;
   int j=n/2;
   int val;

   for(val = 1; val <= n*n; val++) 
   { 
    a[i][j]=val;
    int rei=i;
    int rej=j;
    i = i-1;
    j= j-1;
    
   if  (i<0) 
   {i=n-1;} 
  
   if (j<0)
   {j=n-1;} 
   
   if(a[i][j]!=0)
   {i=rei+1 ;
    j=rej ;  }

   }//end for


  printf("Magic(%d):\n", n);
  for(i=0;i<n;i++)
  {
     for(j=0;j<n;j++)
     {
        printf("%2d ", a[i][j]);
     }//end for
     printf("\n");
  }//end for
  printf("\n");
}//end magic()
