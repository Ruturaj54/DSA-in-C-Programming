//**********************Doubly Circular Linked List***********************

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE Head,PPNODE Tail,int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((*Head == NULL) && (*Tail == NULL))//LL is Empty
    {
        *Head = newn;
        *Tail = newn;
        newn->next = *Tail;
        (*Tail)->prev = newn;
        
    }
    else//LL is Having atleast 1 Node
    {
        newn->next = *Head;
        (*Head)->prev = newn;
        (*Head) = newn;

    }
    (*Tail)->next = (*Head);
    (*Head)->prev = (*Tail);


}
void InsertLast(PPNODE Head,PPNODE Tail,int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((*Head == NULL) && (*Tail == NULL))//LL is Empty
    {
        *Head = newn;
        *Tail = newn;
    }
    else//LL is Having atleast 1 Node
    {
        (*Tail)->next = newn;
        newn->prev = (*Tail);
        (*Tail) = newn;
       
    }
    (*Tail)->next = (*Head);
    (*Head)->prev = (*Tail);

}

void DeleteFisrt(PPNODE Head,PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))//If LL is Empty
    {
        printf("Linked List is Empty \n");
        return;
    }
    else if((*Head)== (*Tail))//if LL has 1 Node
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else //if LL has More than 1 nodes
    {
        *Head = (*Head)->next;
        free((*Head)->prev); // free((*Tail)->next);
        (*Head)->prev = (*Tail);
        (*Tail)->next = *Head;

    }
}
void DeleteLast(PPNODE Head,PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))//If LL is Empty
    {
        printf("Linked List is Empty \n");
        return;
    }
    else if((*Head)== (*Tail))//if LL has 1 Node
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else //if LL has More than 1 nodes
    {
       (*Tail) = (*Tail)->prev;
       free((*Head)->prev); //free((*Tail)->next);
       (*Tail)->next = *Head;
       (*Head)->prev = (*Tail);
    }
}

void Display(PNODE Head,PNODE Tail)
{
    if(Head != NULL && Tail != NULL)
    {
        printf("Containts of Linked List are : \n");

        do
        {
            printf("| %d | <=> ",Head->Data);
            Head = Head->next;
        }while(Head != Tail->next);
        printf("Last node points to first node\n");
    }
}
int Count(PNODE Head,PNODE Tail)
{
    int iCnt = 0;
     do
        {
            iCnt++;
            Head = Head->next;
        }while(Head != Tail->next);
    return iCnt;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int No,int ipos)
{
    int iSize = Count(*Head,*Tail);
    int iCnt = 0;

    PNODE temp = *Head;

    if((ipos > iSize + 1) || (ipos < 1))
    {
        printf("Invalid Position...\n");
        return;
    }

    if(ipos == 1)//Insert at First Node
    {
        InsertFirst(Head,Tail,No);
    }
    else if(ipos == iSize + 1)//Insert At Last Node
    {
        InsertLast(Head,Tail,No);
    }
    else//Insert in between First and Last Node
    {
        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));

        newn->Data = No;
        newn ->next = NULL;
        newn ->prev = NULL;

        for(iCnt = 1;iCnt < ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next=newn;
        newn->prev = temp;

    }
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int ipos)
{
    int iSize = Count(*Head,*Tail);
    int iCnt = 0;

    PNODE temp = *Head;

    if((ipos > iSize + 1) || (ipos < 1))
    {
        printf("Invalid Position...\n");
        return;
    }

    if(ipos == 1)//Insert at First Node
    {
        DeleteFisrt(Head,Tail);
    }
    else if(ipos == iSize)//Insert At Last Node
    {
        DeleteLast(Head,Tail);
    }
    else//Insert in between First and Last Node
    {
    
        for(iCnt = 1;iCnt < ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}
int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;
    int iRet = 0;

    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,21);
    InsertFirst(&First,&Last,11);
    InsertLast(&First,&Last,101);
    InsertLast(&First,&Last,111);
    InsertLast(&First,&Last,121);

    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of Nodes are : %d\n",iRet);

    InsertAtPos(&First,&Last,105,5);
    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteAtPos(&First,&Last,5);
    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of Nodes are : %d\n",iRet);
    DeleteFisrt(&First,&Last);
    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of Nodes are : %d\n",iRet);

    DeleteLast(&First,&Last);
    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of Nodes are : %d\n",iRet);

    

    return 0;
}