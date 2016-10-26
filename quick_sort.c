/*****************************
   hw05: quick sort排序
   姓名: stu012
   學號: 
******************************/
#include <stdio.h> 
#include <string.h>
void showdata(int*);
void quick(int*, int, int);

int main(void)
   {
      int data[18]={10,12,31,89,2013,13,42,88,76,45,21,17,75,8,5,2,1,100}; //原始資料
      quick(data,0,17);
      showdata(data);
      return 0;
   }  
void showdata (int data[])
   {   
     {
      printf("Quick sort:");
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
void quick(int d[], int lf,int rg)
   {
      int i,j,tmp;
      int lf_idx;
      int rg_idx;
      int t;
                  //第一筆鍵值為d[lf]                
       if(lf<rg)
      {
         lf_idx=lf+1;
         rg_idx=rg;
                                                   
search_step:      
      for(t=0;t<18;t++)  
         for(i=lf+1;i<=rg;i++)  //由左向右找出一個鍵值大於d[lf]者
         {
            if(d[i]>=d[lf])
            {
               lf_idx=i;
               break;
            }
            lf_idx++;
         }
         for(j=rg;j>=lf+1;j--) //由右向左找出一個鍵值小於d[lf]者
         {
             if(d[j]<=d[lf])
            {
               rg_idx=j;
               break;
            }
             rg_idx--;
         } 
      
   if(lf_idx < rg_idx) //如果lf_idx <rg_idx  則d[lf_idx]和 [rg_idx]互換
        {
            tmp=d[lf_idx];
            d[lf_idx]=d[rg_idx];
            d[rg_idx]=tmp;
            goto search_step; //繼續執行步驟
        }
  
      if(lf_idx >=rg_idx); //如果lf_idx 大於等於 rg_idx 則將d[lf]跟 d[rg]互換
        {
            tmp=d[lf];
            d[lf]= d[rg_idx];
            d[rg_idx]=tmp;  //並以rg_idx為基準點 分成左右兩半
            quick(d,lf,rg_idx-1); //以遞迴方式分別為左右兩半進行排序
            quick(d,rg_idx+1,rg);  //直到排序完成
        }
      }
    } 
