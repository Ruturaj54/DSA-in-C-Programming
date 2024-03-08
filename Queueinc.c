//******************Queue DataStructure***********************

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


//Void InsertLast(PPNODE Head,int no)
void Enqueue(PPNODE Head,int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if((*Head)== NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;

        }
        temp->next = newn;
    }
}

int Dequeue(PPNODE Head)
{
    PNODE temp = *Head;
    int Value = 0;

    if((*Head)== NULL)
    {
        printf("The Queue is Already Empty\n");
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
        printf("| %d | ",Head->data);
        Head = Head->next;
    }
    printf("\n");
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    Enqueue(&First,11);
    Enqueue(&First,21);
    Enqueue(&First,51);
    Enqueue(&First,101);
    Enqueue(&First,111);
    
    Display(First);
    iRet = Dequeue(&First);
    printf("Removed Elements from queue are : %d\n",iRet);

    iRet = Dequeue(&First);
    printf("Removed Elements from queue are : %d\n",iRet);

    return 0;
}