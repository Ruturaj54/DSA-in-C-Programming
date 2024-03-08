//**************Singly Circular Linked List*****************

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next; //self referential structure
}NODE, *PNODE, **PPNODE;

/*
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
*/

void InsertFirst(PPNODE Head,PPNODE Tail,int no )
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if((*Head) == NULL && (*Tail) == NULL)  //LL is Empty
    {
        *Head = newn;
        *Tail = newn;
        (*Tail)->next = *Head; //To make circular connection
    }
    else   //LL has Atleat 1 node
    {
        newn->next = *Head;
        *Head = newn;
        (*Tail)->next = *Head;
    }
    
}

void InsertLast(PPNODE Head,PPNODE Tail,int no )
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if((*Head) == NULL && (*Tail) == NULL)  //LL is Empty
    {
        *Head = newn;
        *Tail = newn;
        (*Tail)->next = *Head; //To make circular connection
    }
    else   //LL has Atleat 1 node
    {
        (*Tail)->next = newn;
        *Tail = newn;
        (*Tail)->next = *Head;

    }

}


void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if((*Head) == NULL && (*Tail) == NULL)
    {
        printf("Linked list is Empty..\n");
        return;
    }
    else if((*Head) == (*Tail))
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        (*Head) = (*Head)->next;
        free((*Tail)->next);
        (*Tail)->next = *Head;
    }
}
void DeleteLast(PPNODE Head,PPNODE Tail)
{
    PNODE temp = *Head;
    if((*Head) == NULL && (*Tail) == NULL)
    {
        printf("Linked list is Empty..\n");
        return;
    }
    else if((*Head) == (*Tail))
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
       while(temp->next != (*Tail))
       {
            temp = temp->next;
       }
       free(*Tail);
       (*Tail) = temp; 
       (*Tail)->next = (*Head);
    } 
}


void Display(PNODE Head,PNODE Tail)
{
    printf("Contents of Singly Circular Linked list : \n");
    
    if(Head != NULL && Tail != NULL)
    {
        do
        {
            printf("| %d | ->",(Head)->data);
            Head = Head->next;
        }while(Head != Tail->next);

        printf("Address of First Node\n");
    }
}

int Count(PNODE Head,PNODE Tail)
{
    int iCnt = 0;
    if(Head != NULL && Tail != NULL)
    {
        do
        {
           iCnt++;
            Head = Head->next;
        }while(Head != Tail->next);

    }
    return iCnt;
}
void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int ipos )
{
    int Size = 0;
    Size = Count(*Head,*Tail);
    int iCnt = 0;
    PNODE temp = (*Head);

    PNODE newn = NULL;

    if((ipos < 1) || (ipos > Size+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(Head,Tail,no);
    }
    else if(ipos == Size+1)
    {
        InsertLast(Head,Tail,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1;iCnt < ipos - 1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
         
    }
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int ipos)
{
    int Size = 0;
    Size = Count(*Head,*Tail);
    int iCnt = 0;
    PNODE temp = (*Head);
    PNODE targetedNode;

    if((ipos < 1) || (ipos > Size))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(ipos == Size)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        for(iCnt = 1;iCnt < ipos - 1;iCnt++)
        {
            temp = temp->next;
        }
        targetedNode = temp->next;
        temp->next = temp->next->next;
        free(targetedNode);
    }
    
}

int main()
{
    int iRet =0;
    PNODE First = NULL;
    PNODE Last = NULL; //#

    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,21);
    InsertFirst(&First,&Last,11);

    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of Nodes are : %d\n",iRet);

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

    DeleteFirst(&First,&Last);
    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteLast(&First,&Last);
    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteAtPos(&First,&Last,4);
    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of Nodes are : %d\n",iRet);

    return 0;
}