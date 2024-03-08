//******************Stack DataStructure***********************

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

//void InsertFirst(PPNODE Head,int No)
void Push(PPNODE Head,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if((*Head)== NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = (*Head);
        *Head = newn;
    }
}
//Void DeleteFirst(PPNODE Head)
int pop(PPNODE Head)
{
    PNODE temp = *Head;
    int Value = 0;

    if((*Head)== NULL)
    {
        printf("The Stack is Already Empty\n");
    }
    else
    {
        Value = (*Head)->data;
        *Head = (*Head)->next;
        free(temp);
    }
    return Value;
}

void Display(PNODE Head)
{
    printf("Elements of stack are : \n");

    while(Head != NULL)
    {
        printf("| %d |\n",Head->data);
        printf(" ____\n");
        Head = Head->next;
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    Push(&First,101);
    Push(&First,51);
    Push(&First,21);
    Push(&First,11);
    
    Display(First);

    iRet = pop(&First);
    printf("Popped Element is : %d\n",iRet);

    iRet = pop(&First);
    printf("Popped Element is : %d\n",iRet);

    iRet = pop(&First);
    printf("Popped Element is : %d\n",iRet);

    iRet = pop(&First);
    printf("Popped Element is : %d\n",iRet);

    return 0;
}