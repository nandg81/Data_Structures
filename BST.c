/*Program to implement binary search tree
Author: Nandagopal*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//defining the structure of each node
typedef struct node
{
        int data;
        struct node *lchild;
        struct node *rchild;
}NODE;
//function to insert an element
void insert(int x,NODE *root)
{
        NODE *ptr=root;
        NODE *ptr1=root;
        NODE *new;
        int flag=0;
        while((ptr!=NULL)&&(flag==0))
        {
                if(x<(ptr->data))
                {
                        ptr1=ptr;
                        ptr=ptr->lchild;
                }
                else if(x>(ptr->data))
                {
                        ptr1=ptr;
                        ptr=ptr->rchild;
                }
                else
                {
                        flag=1;
                        printf("\nItem already exists");
                }
        }
        if(ptr==NULL)
        {
                new=(NODE*)malloc(sizeof(NODE));
                new->data=x;
                new->lchild=NULL;
                new->rchild=NULL;
                if((ptr1->data)<x)
                        ptr1->rchild=new;
                else
                        ptr1->lchild=new;
                printf("\n%d has been inserted",x);
        }
}
//function to delete an element
void delete(int x,NODE *root)
{
        NODE *ptr=root;
        NODE *ptr1=root;
        NODE *ptr2,*ptr3;
        int flag=0;
        while(ptr!=NULL)
        {
                if(x==(ptr->data))
 {
                        flag=1;
                        break;
                }
                else if(x<(ptr->data))
                {
                        ptr1=ptr;
                        ptr=ptr->lchild;
                }
                else
                {
                        ptr1=ptr;
                        ptr=ptr->rchild;
                }
        }
        if(flag==1)
        {
                if((ptr->lchild==NULL)&&(ptr->rchild==NULL))//if it has no child
                {
                        if(ptr1->lchild==ptr)
                        {
                                ptr1->lchild=NULL;
                                free(ptr);
                        }
                        else
                        {
                                ptr1->rchild=NULL;
                                free(ptr);
                        }
                }
                else if((ptr->lchild==NULL)&&(ptr->rchild!=NULL)||(ptr->lchild!=NULL)&&(ptr->rchild==NULL))//if it has only one child
                {
                        if(ptr==ptr1->lchild)
                        {
                                if(ptr->lchild==NULL)
                                        ptr1->lchild=ptr->rchild;
                                else
                                        ptr1->lchild=ptr->lchild;
                        }
                        else
                        {
                                if(ptr->rchild==NULL)
                                        ptr1->rchild=ptr->rchild;
                                else
                                        ptr1->rchild=ptr->lchild;
                        }
                        free(ptr);
                }
                else//if it has two children
                {
                        ptr2=ptr->rchild;
                        while(ptr2->lchild->lchild!=NULL)
                        {
                                ptr3=ptr2;
                                ptr2=ptr2->lchild;
                        }
                        ptr->data=ptr2->data;
                        ptr3->lchild=NULL;
                        free(ptr2);
                }
    printf("\n%d deleted",x);
        }
        else
        {
                printf("\nItem not found");
        }
}
//function to search for an element
void search(int x,NODE *root)
{
        NODE *ptr=root;
        int flag=0;
        while(ptr!=NULL)
        {
                if(ptr->data==x)
                {
                        flag=1;
                        break;
                }
                else if((ptr->data)>x)
                        ptr=ptr->lchild;
                else
                        ptr=ptr->rchild;
        }
        if(flag==1)
                printf("\n%d is present in the tree",x);
        else
                printf("\n%d is not present in the tree",x);
}
//fucntion to display the elements
void display(NODE *root)
{
        NODE *ptr=root;
        if(ptr!=NULL)
        {
                display(ptr->lchild);
                printf("%d ",ptr->data);
                display(ptr->rchild);
        }
}
//main function
main()
{
        NODE *root;
        int x,ch;
        printf("\nBINARY SEARCH TREE\n");
        printf("\nEnter the value in the root node ");
        scanf("%d",&x);
        root=(NODE*)malloc(sizeof(NODE));
        root->data=x;//assigning the root node with value
        root->lchild=NULL;
        root->rchild=NULL;
        while(1)
        {
                printf("\n\nPress\n1.Insert an element into the tree");
                printf("\n2.Delete an element from the tree");
                printf("\n3.Search for an element");
                printf("\n4.Display the elements in ascending order");
                printf("\n5.Exit\n");
                scanf("%d",&ch);
 if(ch==1)
                {
                        printf("\nEnter the value to be inserted ");
                        scanf("%d",&x);
                        insert(x,root);
                }
                else if(ch==2)
                {
                        printf("\nEnter the value to be deleted ");
                        scanf("%d",&x);
                        delete(x,root);
                }
                else if(ch==3)
                {
                        printf("\nEnter the element to be searched for ");
                        scanf("%d",&x);
                        search(x,root);
                }
                else if(ch==4)
                {
                        printf("\nThe elements of the BST\n");
                        display(root);
                }
                else
                        exit(0);
        }
}
