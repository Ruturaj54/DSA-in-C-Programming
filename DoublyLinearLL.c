//****************Doubly linear Linked List******************

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;  // #
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL; // # 

    if(*Head == NULL) //LL is Empty
    {
        *Head = newn;   
    }
    else
    {
       newn->next = *Head;
       (*Head)->prev = newn;//#
       *Head = newn;
    }
}

void InsertLast(PPNODE Head,int no)
{
    
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL; // # 

    if(*Head == NULL) //LL is Empty
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
        newn->prev = temp; //#
    }

}

void DeleteFirst(PPNODE Head) //empty LL
{
    if(*Head == NULL)
    {
        return;
    }
    else if(((*Head)->next == NULL) && ((*Head)->prev == NULL)) //# Single node
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        (*Head) = (*Head)->next;
        free((*Head)->prev);
        (*Head)->prev = NULL;


    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        return;
    }
    else if(((*Head)->next == NULL) && ((*Head)->prev == NULL)) //# Single node
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;


    }

}


void Display(PNODE Head)
{
    printf("Containts of Linked List are:\n");

    printf("NULL <=> ");
    while(Head != NULL)
    {
        printf("| %d | <=> ",Head->data);
        Head = Head->next;
    }printf("NULL \n");
   
}
int Count(PNODE Head)
{
    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }

    return iCnt;
}

void InsertAtPos(PPNODE Head,int no,int ipos)
{
    int Size = 0;
    PNODE temp = *Head;
    PNODE newn = NULL;
    Size = Count(*Head);
    int iCnt = 0;

    if((ipos < 1) || (ipos > Size + 1))
    {
        printf("Invalid position..\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(Head,no);

    }
    else if(ipos == Size + 1)
    {
        InsertLast(Head,no);
    }
    else
    {
        
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;  //#

        for(iCnt = 1;iCnt < ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;//1
        temp->next->prev = newn;//2
        temp->next = newn;//3
        newn->prev = temp;//4
    
    }

}
void DeleteATPos(PPNODE Head,int ipos)
{
    int iCnt = 0;
    int Size = 0;
    PNODE temp = *Head;
    Size = Count(*Head);

    if((ipos < 1) || (ipos > Size))
    {
        printf("Invalid position..\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(Head);

    }
    else if(ipos == Size + 1)
    {
        DeleteLast(Head);
    }
    else
    {
        for(iCnt = 1;iCnt < ipos - 1;ipos++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;//1

        free(temp->next->prev);//2
        
        temp->next->prev = temp; //3


    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    Display(First);
    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    InsertLast(&First,101);
    InsertLast(&First,111);
    InsertLast(&First,121);

    Display(First);
    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    DeleteFirst(&First);
    Display(First);
    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    DeleteLast(&First);
    Display(First);
    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    InsertAtPos(&First,105,2);
    Display(First);
    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);

    DeleteATPos(&First,2);

     Display(First);
    iRet = Count(First);

    printf("Number of Nodes are : %d\n",iRet);



    return 0;
}