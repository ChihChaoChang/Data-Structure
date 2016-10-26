/*****************************
   hw05: 排序
   姓名: stu012
   學號: 
******************************/
#include <stdio.h> 
#include <string.h>

void bubble (int*); // 宣告氣泡排序副程式
void showdata (int*); //宣告列印陣列副程式
void radixSort(int[]);// 宣告基數排序副程式
void printdata (int data[]);//宣告列印陣列副程式
int main (void)
   {
    int data[18]={10,12,31,89,2013,13,42,88,76,45,21,17,75,8,5,2,1,100}; //原始資料
    bubble (data);    
    int data2[18]={10,12,31,89,2013,13,42,88,76,45,21,17,75,8,5,2,1,100}; //原始資料
    radixSort(data2);
    return 0;
    }
    
void showdata (int data[])  //利用迴圈列印資料
  {
    {
      printf("Bubble sort:");
      printf("\n");
    }
      int i;      
        for(i=0; i<18; i++)       
        { 
        if(i==17)
            {
             printf("%d",data[i]);  
             printf("\n");
            }
          else
            {
            printf("%d,",data[i]);        
            }
        } 
         printf("\n");   
    }

void bubble (int data[])
   {
      int i,j,tmp,flag;
      for(i=17;i>=0;i--)
      {
         flag=0;     //flag 用來判斷是否有執行交換的動作
         for(j=0;j<i;j++)
            {
               if(data[j+1] < data[j])
                  {
                     tmp=data[j];
                     data[j]=data[j+1];
                     data[j+1]=tmp;
                     flag++;  //如果有執行過交換 則flag 不為0
                  }
            }
         if(flag==0)
         break;  //執行完一次掃描 判斷是否做過交換動作 如果沒有交換動作 就完成排序 就跳出迴圈
      }
      showdata(data);
   }    

void radixSort(int data2[]) 
{
    int i,j,k,n,m; //n為基數 由個位數開始排序
    for(n=1;n<=1000;n=n*10)
    {
    
    int tmp[10][100]={0};//設定暫存陣列 [0~9位數] [資料個數] 所有內容均為0
    for(i=0;i<18;i++) //比對所有資料
    {
      m=(data2[i]/n)%10; //為n位數的值 (42/10)%10=4
      tmp[m][i]=data2[i]; //把data[i]的值暫存在tmp裡
    }
    k=0;
    for(i=0;i<10;i++)
    { 
      for(j=0;j<18;j++)
      {
         if(tmp[i][j]!=0)  //一開始設定 tmp={0} 故不為0者就是
         {
         data2[k]=tmp[i][j]; //data 暫存在tmp裡的值 
          k++; //回到data[]裡
         }
      }
    }
   }
   printdata(data2);
}
void printdata (int data2[]) //利用迴圈列印資料
{
    printf("Radix sort:  "); 
    printf("\n"); 
    int i,j;
    for(i = 0; i < 18; i++) 
       {
        if(i==17)
            {
                printf("%d ", data2[i]); 
            }  
        else
            {
                printf("%d,", data2[i]); 
            }    
       }    
     printf("\n");  
}
