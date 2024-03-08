//------------------------------------------------------------
//******************BINARY SEARCH TREE************************
//------------------------------------------------------------


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Head,int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*Head == NULL)//The BST is empty //will execute for 1 time for Root node
    {
        *Head = newn;
    }
    else//BST has atleast 1 node in it
    {
        while(1)    //it is unconditional loop //for(;;) can be used
        {
            if(no == temp->data)
            {
                printf("Unable to insert as the data is already present in the BST\n");
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;

            }
        }
    }
}

void Inorder(PNODE Head)
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);
        printf("%d\n",Head->data);
        Inorder(Head->rchild);
    }
}

void Preorder(PNODE Head)
{
    if(Head != NULL)
    {
        printf("%d\n",Head->data);
        Inorder(Head->lchild);
        Inorder(Head->rchild);
    }
}

void Postorder(PNODE Head)
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);
        Inorder(Head->rchild);
        printf("%d\n",Head->data);
    }
}

bool Search(PNODE Head,int no)
{
    bool flag = false;

    if(Head == NULL)
    {
        printf("Tree is empty\n");
        return false;

    }
    while(Head != NULL)
    {
        if(no == Head->data)
        {
            flag = true;
            break;
        }
        else if(no > Head->data)
        {
            Head = Head->rchild;
        }
        else if(no < Head->data)
        {
            Head = Head->lchild;
        }

    }
    return flag;
}

int Count(PNODE Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        iCnt++;
        Count(Head->lchild);
        Count(Head->rchild);
    }
    return iCnt;
}

int CountLeaf(PNODE Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        if(Head->lchild == NULL && Head->rchild == NULL)
        {
            iCnt++;
        }

        CountLeaf(Head->lchild);
        CountLeaf(Head->rchild);
    }
    return iCnt;
}

int CountParent(PNODE Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        if(Head->lchild != NULL || Head->rchild != NULL)
        {
            iCnt++;
        }

        CountParent(Head->lchild);
        CountParent(Head->rchild);
    }
    return iCnt;
}

int Summmation(PNODE Head)
{
    static int iSum = 0;

    if(Head != NULL)
    {
        iSum = iSum + Head->data;
        Summmation(Head->lchild);
        Summmation(Head->rchild);
    }
    return iSum;
}

int CountEven(PNODE Head)
{
    static int EveniCnt = 0;

    if(Head != NULL)
    {
        if(Head->data % 2 == 0)
        {
            EveniCnt++;
        }
        CountEven(Head->lchild);
        CountEven(Head->rchild);
    }
    return EveniCnt;
}


int CountOdd(PNODE Head)
{
    static int OddiCnt = 0;

    if(Head != NULL)
    {
        if(Head->data % 2 != 0)
        {
            OddiCnt++;
        }
        CountOdd(Head->lchild);
        CountOdd(Head->rchild);
    }
    return OddiCnt;
}

int main()
{
    PNODE first = NULL;
    bool bRet = false;
    int iRet = 0;
    int iValue = 0;

    Insert(&first,21);
    Insert(&first,11);
    Insert(&first,17);
    Insert(&first,45);
    Insert(&first,10);
    Insert(&first,78);
    Insert(&first,30);
    Insert(&first,5);
    //Insert(&first,11);


    printf("Inorder Traversal is : \n");
    Inorder(first);

    iRet = Count(first);
    printf("Number of Nodes in the BST are : %d\n",iRet);

    iRet = CountLeaf(first);
    printf("Number of Leaf Nodes in the BST are : %d\n",iRet);

    iRet = CountParent(first);
    printf("Number of Parent Nodes in the BST are : %d\n",iRet);

    iRet = Summmation(first);
    printf("Summation of all Elements in BST are : %d\n",iRet);

    iRet = CountEven(first);
    printf("Number of Even numbers in BST are : %d\n",iRet);

    iRet = CountOdd(first);
    printf("Number of Odd numbers in BST are : %d\n",iRet);

    // printf("Preorder Traversal is : \n");
    // Preorder(first);

    // printf("Postorder Traversal is : \n");
    // Postorder(first);

    printf("Enter the data that you want to search for : \n");
    scanf("%d",&iValue);

    bRet = Search(first,iValue);

    if(bRet == true)
    {
        printf("The Element is present...\n");
    }
    else
    {
        printf("The Element Not present...\n");
    }

    return 0;
}