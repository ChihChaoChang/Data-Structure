/*****************************
   hw03: 走迷宮遞迴
   姓名: stu012
   學號: 
******************************/
#include <stdio.h>
#include <stdlib.h>
#define RIGHT go_go_mouse(x,y+1)//*定義右方位置//
#define LEFT  go_go_mouse(x,y-1)//*定義左方位置//
#define DOWN  go_go_mouse(x+1,y)//*定義下方位置//
#define UP    go_go_mouse(x-1,y)//*定義上方位置//

int main(void)
{

int maze[7][10] = 
     {       
                
     1,1,1,1,1,1,1,1,1,1,//*宣告迷宮陣列
     1,0,1,0,1,0,0,0,0,1,
     1,0,1,0,1,0,1,1,0,1,
     1,0,1,0,1,1,1,0,0,1,
     1,0,1,0,0,0,0,0,1,1,
     1,0,0,0,1,1,1,0,0,1,
     1,1,1,1,1,1,1,1,1,1,
         
      };
     int i,j;
     int x = 5;
     int y = 8;

     int go_go_mouse(int x,int y)
      {       
       if (x==1 && y==1)        //*終止條件
        {
          maze[x][y] = 2;             
          return 1;                   
        }
        else
           if (maze[x][y] == 0)     
           {
             maze[x][y] = 2;          
              if ( ( UP+DOWN+LEFT+RIGHT ) > 0 ) //找到路傳回值
        
            return 1;
             else
             {
               maze[x][y] = 0;      
               return 0;
             }
            }
      else
         return 0;
       }
     
   go_go_mouse(x,y);  //跟作業二不同之處 列印時要呼喚函數
   printf("Path:\n");
   //印出迷宮
    for ( i = 0; i <= 6; i++)
    {
      for ( j = 0; j <= 9; j++)
      {
         printf("%d",maze[i][j]);
      }//end for
      printf("\n");
   }//end for
   
   return 0;
}//end main()
