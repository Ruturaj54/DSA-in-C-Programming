//*********Singly Linear Linked list**************

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn; 
    }
    else
    {
        newn->next = *Head; //navin mulga junya mulachya angavr hat
        *Head = newn;
    }
    
}

void InsertLast(PPNODE Head,int No)
{
    //Temporary pointer for linked list travelsal

    PNODE Temp = *Head;

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn; 
    }
    else
    {
        //Travel the LL till last node
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        //Add the address of new node at the end of last node
        Temp->next = newn;
    }
    
}
void Display(PNODE First)
{
    printf("Contents of Linked List : \n");

    while(First != NULL)
    {
        printf("| %d | -> ",First->data);
        First = First->next;
    }
    printf("NULL\n");
}


int count(PNODE First)
{
    int iCnt = 0;
    while(First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}

void DeleteFirst(PPNODE Head)
{

    if(*Head == NULL) //case 1
    {
        return;
    }
    else if((*Head) -> next == NULL) //case 2
    {
        free(*Head);
        *Head = NULL;
    }
    else        //case 3
    {
        PNODE temp = *Head;
        *Head = (*Head)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    if(*Head == NULL) //case 1
    {
        return;
    }
    else if((*Head) -> next == NULL) //case 2
    {
        free(*Head);
        *Head = NULL;
    }
    else        //case 3
    {
        PNODE temp= *Head;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp->next = NULL;

    }
}

void InsertAtPos(PPNODE Head,int No,int iPos)
{
    int Size = 0;
    Size = count(*Head);
    PNODE newn = NULL;
    int i = 0;
    PNODE temp = *Head;

    //Case 1 : Invalid Position
    if((iPos > Size + 1) || (iPos < 1))
    {
        printf("Invalid Position for Insertion\n");
        return;
    }

    //Case 2 : First Position
    if(iPos == 1)
    {
        InsertFirst(Head,No);
    }
    //Case 3 : Last Position
    else if(iPos == Size + 1)
    {
        InsertLast(Head,No);
    }
    //Case 4 : Position is in between First and Last (eg. 5)
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = No;
        newn->next = NULL;

        for(i = 1;i < iPos - 1;i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }

}

void DeleteAtPos(PPNODE Head,int iPos)
{
    int Size = 0;
    Size = count(*Head);
    PNODE temp = *Head;
    PNODE targetednode = NULL;
    int i = 0;
    

    //Case 1 : Invalid Position
    if((iPos > Size) || (iPos < 1))
    {
        printf("Invalid Position for Deletion \n");
        return;
    }

    //Case 2 : First Position
    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    //Case 3 : Last Position
    else if(iPos == Size)
    {
        DeleteLast(Head);
    }
    //Case 4 : Position is in between First and Last (eg. 5)
    else
    {
        for(i = 1;i < iPos-1;i++)
        {
            temp = temp->next;
        }
        targetednode = temp->next;
        
        temp->next = temp->next->next;
        free(targetednode);
    }
}

int main()
{
    PNODE First = NULL;  //Node cha Adrress store karnyasathi
    int iRet = 0;

    InsertFirst(&First,111);
    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    /*
    Display(First);
    iRet = count(First);
    printf("Number of Nodes are : %d\n",iRet);
    */

    InsertLast(&First,121);
    //InsertLast(&First,151);

    InsertAtPos(&First,105,5);

    Display(First);
    iRet = count(First);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteAtPos(&First,5);

    Display(First);
    iRet = count(First);
    printf("Number of Nodes are : %d\n",iRet);

    /*
    DeleteFirst(&First);
    Display(First);
    iRet = count(First);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteLast(&First);
    Display(First);
    iRet = count(First);
    printf("Number of Nodes are : %d\n",iRet);
    */

    return 0;
}