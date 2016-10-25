/*****************************
   hw02: 走迷宮
   姓名: 張智超
   學號: stu012
******************************/
#include <stdio.h>
#include <stdlib.h>
#define RIGHT maze[x][y+1]//*定義右方位置//
#define LEFT  maze[x][y-1]//*定義左方位置//
#define DOWN  maze[x+1][y]//*定義下方位置//
#define UP    maze[x-1][y]//*定義上方位置//

struct stack_node
{
   int x;
   int y;
   struct stack_node *next;
};
typedef struct stack_node stack_list;
typedef stack_list *link;

link path = NULL;

link push(link stack,int x,int y)
{
   link new_node;

   new_node = ( link ) malloc(sizeof(stack_list));
   if ( !new_node ){
      printf("Error\n");
      return NULL;
   }//end if
   new_node->x = x;
   new_node->y = y;
   new_node->next = stack;
   stack = new_node;
   return stack;
}//end push

link pop(link stack,int *x,int *y)
{
  link top;
  if (stack !=NULL)
  { 
    top=stack;
    stack=stack->next;
    *x=top->x;
    *y=top->y;
    free (top);
    return stack;
  }
  else {
  *x=-1;
    return stack;
  }
  }//end pop


int main(void)
{
   int maze[7][10] = {
  
     1,1,1,1,1,1,1,1,1,1,//*宣告迷宮陣列*//
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
   
   while ( x != 1 || y != 1 )
   { maze[x][y]=2;
    if (UP==0)
    {
      x-=1;
      path=push(path,x,y);
    }
    else if (DOWN==0)
    {
      x+=1;
      path=push(path,x,y);
    }    
    else if (LEFT==0)
    {
      y-=1;
      path=push(path,x,y);
    }
    else if (RIGHT==0)
     {
     y+=1;
     path=push(path,x,y);
     }
      
    
     else 
     { maze[x][y]=3;
     path=pop(path,&x,&y);
     }
      
   }//end while
   
   
   maze[x][y] = 2;
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
