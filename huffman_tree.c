#include <stdio.h> 
#include <string.h>

typedef struct treenode
{
    char *ch;
    int weight;
    char *pos;
    struct treenode *leftnode;
    struct treenode *rightnode;
} tn;

int asciiCom(char *a, char *b);
tn **getNodeArray(char *str, int *variety);
tn *genHFtree(tn **nodeArray, int variety);
tn **sortTree(tn **nodeArray, int variety);
void printNode(tn *node,char c);
void printTree(tn *node);
void assignPos(tn *node);
void sortStr(char *ch);

void main(int argc, char *argv[])
{
    int cn;
    char *input = "CACABCBDEAAEBCADAECAAAAACDDEDAABAABADCEBBABEDBACAEABCDBAABEAACBBBB";
    tn **nArray = getNodeArray(input, &cn);
    tn *root = genHFtree(nArray,cn);
    printTree(root);
}

int asciiCom(char *a, char *b)
{
    int asum = 0;
    int bsum = 0;
    int i;
    for(i = 0;i < strlen(a);i++)
    {
        asum+=(int)a[i];//this part is used to transfer ASCII code to intergers to compare
    }
    
    for(i = 0;i < strlen(b);i++)
    {
        bsum+=(int)b[i];
    }
    
    if(asum > bsum)
        return 1;
    else if(asum == bsum)
        return 0;
    else
        return -1;
}

tn **getNodeArray(char *str, int *variety)
{
    tn **nodeArray;
    char *chs = (char *)calloc(strlen(str)+1, sizeof(char));// allocate memory to store the kind of character, A,B,C,D,E
    int *charCount = (int *)calloc(strlen(str), sizeof(int));// allocate memory to store the times  of character, A,B,C,D,E
    char *index;
    int i;
    for(i = 0;i < strlen(str);i++)
    {
        if((index = strchr(chs, str[i])) != NULL) //want to count how many different kind of characters ex:A,B 
        {
            charCount[index - chs]++;
        }
        else
        {
            charCount[strlen(chs)]++; //count the chs array how many times the character is
            chs[strlen(chs)] = str[i];
        }
    }
    
    nodeArray = (tn **)calloc(strlen(chs),sizeof(tn*));
    for(i = 0;i < strlen(chs);i++)
    {
        nodeArray[i] = (tn *)calloc(1,sizeof(tn));
        nodeArray[i]->ch = (char *)calloc(1+1,sizeof(char));
        nodeArray[i]->ch[0] = chs[i];
        nodeArray[i]->weight = charCount[i]; //count how many times in the kind ex: A:8 times
        nodeArray[i]->leftnode = NULL; //  first step to set left node nothing to differenciate
        nodeArray[i]->rightnode = NULL; //  first step to set Right node nothing to differenciate
    }
    
    *variety = strlen(chs); //variety means how many kinds of characters
    return nodeArray;
}

tn **sortTree(tn **nodeArray, int variety)
{
    int i,j;
    tn *tmp;
    for(i = 0;i < variety;i++)
        for(j = i+1;j < variety;j++)
            if(nodeArray[i]->weight > nodeArray[j]->weight)
			// tmp is used to remember the position of node array 
			//ex. after connect the node, the first tmp to memrize the DE and set DE to 0 compare to the rest of C(1),B(2),A(3)
            //then tmp to remeber the CDE is 0 to compare the the rest of B,A
            // until the ABCDE become NULL
			{
                tmp = nodeArray[i];
                nodeArray[i] = nodeArray[j];
                nodeArray[j] = tmp;
            }
            else if(nodeArray[i]->weight == nodeArray[j]->weight && asciiCom(nodeArray[i]->ch, nodeArray[j]->ch) < 0)
            {
                tmp = nodeArray[i];
                nodeArray[i] = nodeArray[j];
                nodeArray[j] = tmp;
            }
            
    if(nodeArray[0]->weight == nodeArray[1]->weight && asciiCom(nodeArray[0]->ch, nodeArray[1]->ch) > 0)
	// if their sime are the same using ASCII code to judge
    {
        tmp = nodeArray[0];
        nodeArray[0] = nodeArray[1];
        nodeArray[1] = tmp;
    }
    
    return nodeArray;
}

tn *genHFtree(tn **nodeArray, int variety)
{
    int i;
    tn *tmp;
    for(variety;variety > 1;variety--)
    {
        nodeArray = sortTree(nodeArray, variety);
        tmp = (tn *)calloc(1,sizeof(tn));
        tmp->ch = (char *)calloc(1+strlen(nodeArray[0]->ch)+strlen(nodeArray[1]->ch),sizeof(char));
        strcpy(tmp->ch,nodeArray[0]->ch);//copy the array to another array
        strcat(tmp->ch,nodeArray[1]->ch);//to connect the array to form a new array
        tmp->weight = nodeArray[0]->weight + nodeArray[1]->weight;
        tmp->leftnode = nodeArray[0];
        tmp->rightnode = nodeArray[1];
        nodeArray[0] = tmp;
        nodeArray[0]->pos = NULL;// to set the original node is NULL without any value
        for(i = 1;i < variety-1;i++)
        {
            nodeArray[i] = nodeArray[i+1];
        }
    }
    assignPos(nodeArray[0]);
    return nodeArray[0];
}

void assignPos(tn *node)
{
    if(node->leftnode == NULL) // if there is no more left node then finish 
        return;
        
    if(node->pos == NULL) //give the left 'o' and right node '1'
    {
        node->leftnode->pos = (char *)calloc(1+1,sizeof(char));
        strcpy(node->leftnode->pos,"0");
        node->rightnode->pos = (char *)calloc(1+1,sizeof(char));
        strcpy(node->rightnode->pos,"1");
    }
    else //copy the original pos and give the new '0','1' and do it recurively
    {
        node->leftnode->pos = (char *)calloc(strlen(node->pos) + 2,sizeof(char));
        strcpy(node->leftnode->pos, node->pos);
        strcat(node->leftnode->pos, "0");
        node->rightnode->pos = (char *)calloc(strlen(node->pos) + 2,sizeof(char));
        strcpy(node->rightnode->pos, node->pos);
        strcat(node->rightnode->pos, "1");
    }
    assignPos(node->leftnode);
    assignPos(node->rightnode);
}

void printTree(tn *node)
{
    int i;
    printf("Huffman_Code_Table:\n");
    sortStr(node->ch);
    for(i = 0;i < strlen(node->ch);i++)
    {
        printNode(node, node->ch[i]);
    }
}

void sortStr(char *ch)
{
    int i,j;
    char tmp;
    for(i = 0;i < strlen(ch);i++)
        for(j = i+1;j < strlen(ch);j++)
            if(ch[i] > ch[j])
            {
                tmp = ch[i];
                ch[i] = ch[j];
                ch[j] = tmp;
            }
}

void printNode(tn *node,char c)
{
    if(strchr(node->ch, c) != NULL)
        if(strlen(node->ch) > 1)
        {
            printNode(node->leftnode, c);
            printNode(node->rightnode, c);
        }
        else if(strlen(node->ch) == 1)
            printf("%s\t%d\t%s\n",node->ch,node->weight,node->pos);
}


