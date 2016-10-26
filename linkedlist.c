/*****************************
   hw03: 多項式的加法與乘法
   姓名: stu012
   學號: 
******************************/
#include<stdio.h>

typedef struct poli {    // 宣告結構
    int coefficient;
    int exponent;
    struct poli *next;  //指針*next
} Poli;

Poli *genPoli(int para[][2],int length);  //宣告函數
Poli *sumPoli(Poli *a, Poli *b);
Poli *mulPoli(Poli *a, Poli *b);
void printPoli(Poli *p);

void main(int argc, char* argv[])
{
    //printf("%d\n",argc);
    int a1[1][2] = {0,0};   //一個pair 裡 兩個單位
    int a2[3][2] = {3,6,1,2,5,1};
    int a3[3][2] = {1,2,1,1,1,0};
    int b1[3][2] = {2,2,3,1,4,0};
    int b2[2][2] = {-1,2,-2,1};
    int b3[1][2] = {2,1};
    Poli *al1 = genPoli(a1,1);  //長度有1個pair
    Poli *al2 = genPoli(a2,3);
    Poli *al3 = genPoli(a3,3);
    Poli *bl1 = genPoli(b1,3);
    Poli *bl2 = genPoli(b2,2);
    Poli *bl3 = genPoli(b3,1);
    Poli *r1,*r2,*r3;
    r1 = mulPoli(al1,bl1);
    r2 = sumPoli(al2,bl2);
    r3 = mulPoli(al3,bl3);
    printf("CASE_1:");
    printPoli(r1);
    printf("\n");
    printf("CASE_2:");
    printPoli(r2);
    printf("\n");
    printf("CASE_3:");
    printPoli(r3);
    printf("\n");
    
    
}


Poli *genPoli(int para[][2],int length)
{
    int i;
    Poli *head,*now,*node;

    for(i = 0;i < length;i++)
    {
        node = (Poli*)malloc(sizeof(Poli));
        node->coefficient = para[i][0];
        node->exponent = para[i][1];
        if(i == 0)
            head = node;
        else
            now->next = node;
        now = node;
    }
    
    now->next = NULL;

    return head; //回傳到函數
}

void printPoli(Poli *p)  //列印
{
    if(p->coefficient == 0)  //當係數為零 列印0
        printf("0");
        
    while(p != NULL)
    {
        if(p->coefficient != 0)
        {
            if(p->coefficient == -1)   //係數為負
                printf("-");
            else if(p->coefficient != 1 ||p->exponent == 0)   //係數不等於一 或 指數等於零時
            
            
                printf("%d",p->coefficient);
                
            if(p->exponent == 1)  //指數等於1時
            {
                printf("x");
            }
            else if(p->exponent != 0) //指數不等於零時
            {
                printf("x^%d",p->exponent);
            }
        }
        p = p->next;
        if(p != NULL && p->coefficient > 0)   //係數為正時 
            printf("+");
    }
 
   
       printf("\n");
}

Poli *sumPoli(Poli *a, Poli *b)   //多項式相加//
{
    Poli *head = NULL;
    Poli *now,*node;
    
    while(1)   //一直執行的迴圈 直到遇見break
        {
        node = (Poli *)malloc(sizeof(Poli)); //分配記憶體
        if(a->exponent > b->exponent) // 如果a的指數比b大
        {
            node->coefficient = a->coefficient;
            node->exponent = a->exponent;
            a = a->next;
        }
        else if(a->exponent == b->exponent)  // 如果a的指數等於b
        {
            node->coefficient = a->coefficient + b->coefficient;
            node->exponent = a->exponent;
            a = a->next;
            b = b->next;
        }
        else
        {
            node->coefficient = b->coefficient; 
            node->exponent = b->exponent;
            b = b->next;
        }
        
        if(head == NULL)  
            head = node;
        else
            now->next = node;
        
        now = node;
        
        if(a == NULL) //如果a做完的話 就把b剩下的加上去就好
        {
            now->next = b;
            break;
        }
        if(b == NULL)// //如果b做完的話 就把a剩下的加上去就好
        {
            now->next = a;
            break;
        }
    }
    return head;
}

Poli *mulPoli(Poli *a, Poli *b)   //多項式相乘//
{
    Poli *head = NULL; //指針沒指東西
    Poli *tmp = NULL;
    Poli *node,*now;
    Poli *b_s = b;  //紀錄起點  讓a能夠循序乘與b的所有項數
    
    while(a != NULL)
    {
        b = b_s;
        while(b != NULL)
        {
            node = (Poli *)malloc(sizeof(Poli));
            node->coefficient = a->coefficient * b->coefficient;   //係數相乘
            node->exponent = a->exponent + b->exponent;            //指數相加
            b = b->next;
            
            if(tmp == NULL)  
                tmp = node;
            else
                now->next = node;
                
            now = node;
        }
        if(head == NULL)
            head = tmp;
        else
            head = sumPoli(head,tmp);
            
        tmp = NULL;
        a = a->next;
    }
    
    return head;
}
