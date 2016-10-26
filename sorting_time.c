/*****************************
   hw08: 測試時間
   姓名: stu012
   學號: 
******************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble (int*,int); 
void showdata (int*,int);
void inputarr (int*,int);

void radixSort(int[],int);
void printdata (int data[],int);
void inputarr2 (int*,int);

int main (void)
   {
    int size,data[100000]={0};
    srand((unsigned)time(NULL));
    printf("請輸入Bubble sort陣列大小(100,000以下):");
    scanf("%d",&size);
    printf("Random data:\n");
    printf("\n");
    inputarr (data,size);
    showdata(data,size);
    time_t start_time, end_time;  //計時
    float total_time = 0;
    start_time = clock();
    printf("Bubble sort:\n");
    printf("\n");
    bubble (data,size);
    end_time = clock();
    total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
    printf("Time : %f sec \n", total_time);
       
    int size2,data2[100000]={0};
    srand((unsigned)time(NULL));
    printf("\n");
    printf("請輸入Radix sort陣列大小(100,000以下):");
    scanf("%d",&size2);
    printf("\n");
    printf("Random data:\n");
    printf("\n");
    inputarr2 (data2,size2);
    printdata(data2,size2);
    printf("\n");
    time_t start_time2, end_time2;  //計時
    float total_time2 = 0;
    start_time2 = clock();
    printf("Radix sort:\n");  
    printf("\n");    
    radixSort(data2,size2);  
    end_time2 = clock();
    total_time2 = (float)(end_time2 - start_time2)/CLOCKS_PER_SEC;
    printf("\n");
    printf("Time : %f sec \n", total_time2); 
    printf("\n");
    
    
    return 0;
    }
    
void inputarr(int data[], int size)
    {
      int i;
      for(i=0;i<size;i++)
        data[i]=(rand()%99999)+1;
    }
void inputarr2(int data2[], int size2)
    {
      int i;
      for(i=0;i<size2;i++)
        data2[i]=(rand()%99999)+1;
    }         
        
        
void showdata (int data[],int size)  //利用迴圈列印資料
  {
    
      int i;      
        for(i=0; i<size; i++)       
        { 
        if(i==size-1)
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

void bubble (int data[],int size)
   {
      int i,j,tmp,flag;
      for(i=size-1;i>=0;i--)
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
      showdata(data,size-1);
   }    

void radixSort(int data2[],int size2) 
{
    int i,j,k,n,m; //n為基數 由個位數開始排序
    for(n=1;n<=size2;n=n*10)
    {
    
    int tmp[10][100000]={0};//設定暫存陣列 [0~9位數] [資料個數] 所有內容均為0
    for(i=0;i<size2;i++) //比對所有資料
    {
      m=(data2[i]/n)%10; //為n位數的值 (42/10)%10=4
      tmp[m][i]=data2[i]; //把data[i]的值暫存在tmp裡
    }
    k=0;
    for(i=0;i<10;i++)
    { 
      for(j=0;j<size2;j++)
      {
         if(tmp[i][j]!=0)  //一開始設定 tmp={0} 故不為0者就是
         {
         data2[k]=tmp[i][j]; //data 暫存在tmp裡的值 
          k++; //回到data[]裡
         }
      }
    }
   }
   printdata(data2,size2);
}
void printdata (int data2[],int size2) //利用迴圈列印資料
{
   // printf("Radix sort:  "); 
   // printf("\n"); 
    int i,j;
    for(i = 0; i < size2; i++) 
       {
        if(i==size2)
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
