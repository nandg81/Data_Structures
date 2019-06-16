/*Program to perform polynomial addition
Author: Nandagopal*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
        int coeff;
        int exp;
        struct node *link;
}NODE;
NODE *pheader,*qheader,*rheader;
void insert(int coeff,int exp,int n)
{
        NODE *new=(NODE*)malloc(sizeof(NODE));
        NODE *ptr;
        if(new==NULL)
        {
                printf("Insufficent memory");
                exit(0);
        }
        if(n==1)
                ptr=pheader;
        if(n==2)
                ptr=qheader;
        if(n==3)
                ptr=rheader;
        while((ptr->link)!=NULL)
                ptr=ptr->link;
        ptr->link=new;
        new->coeff=coeff;
        new->exp=exp;
        new->link=NULL;
}
void display(int n)
{
        NODE *ptr;
        if(n==1)
                ptr=pheader->link;
        if(n==2)
                ptr=qheader->link;
        if(n==3)
                ptr=rheader->link;
        if(ptr==NULL)
                printf("List is empty");
        else
        {
                while(ptr!=NULL)
                {
                        if(ptr->coeff>0)
                                printf("+%dx^%d",ptr->coeff,ptr->exp);
                        else
                                printf("%dx^%d",ptr->coeff,ptr->exp);
                        ptr=ptr->link;
                }
        }
}
void main()
{
        int i,exp,coeff,count=1,size1,size2;
 NODE *pptr,*qptr,*rptr,*new;
        pheader=(NODE*)malloc(sizeof(NODE));
        qheader=(NODE*)malloc(sizeof(NODE));
        rheader=(NODE*)malloc(sizeof(NODE));
        printf("Enter the no of terms of the first polynomial");
        scanf("%d",&size1);
        printf("\nEnter the first polynomial");
        for(i=0;i<size1;i++)
        {
                printf("\nEnter term %d ",i+1);
                printf("\nEnter the coefficient ");
                scanf("%d",&coeff);
                printf("\nEnter the expoenent ");
                scanf("%d",&exp);
                insert(coeff,exp,1);
        }
        printf("Enter the no of terms of the second polynomial");
        scanf("%d",&size2);
        printf("\nEnter the second polynomial");
        for(i=0;i<size2;i++)
        {
                printf("\nEnter term %d ",i+1);
                printf("\nEnter the coefficient ");
                scanf("%d",&coeff);
                printf("\nEnter the exponent ");
                scanf("%d",&exp);
                insert(coeff,exp,2);
        }
        pptr=pheader->link;
        qptr=qheader->link;
        rheader->link=NULL;
        rheader->exp=NULL;
        rheader->coeff=NULL;
        rptr=rheader;
        while((pptr!=NULL)&&(qptr!=NULL))
        {
                if((pptr->exp)==(qptr->exp))
                {
                        new=(NODE*)malloc(sizeof(NODE));
                        rptr->link=new;
                        rptr=new;
                        rptr->coeff=(pptr->coeff)+(qptr->coeff);
                        rptr->exp=pptr->exp;
                        rptr->link=NULL;
                        pptr=pptr->link;qptr=qptr->link;
                }
                else if((pptr->exp)>(qptr->exp))
                {
                        new=(NODE*)malloc(sizeof(NODE));
                        rptr->link=new;
                        rptr=new;
                        rptr->coeff=pptr->coeff;
                        rptr->exp=pptr->exp;
                        rptr->link=NULL;
                        pptr=pptr->link;
                }
                else if((pptr->exp)<(qptr->exp))
                {
                        new=(NODE*)malloc(sizeof(NODE));
                        rptr->link=new;
 rptr=new;
                        rptr->coeff=qptr->coeff;
                        rptr->exp=qptr->exp;
                        rptr->link=NULL;
                        qptr=qptr->link;
                }
        }
        while(pptr!=NULL)
        {
                new=(NODE*)malloc(sizeof(NODE));
                rptr->link=new;
                rptr=new;
                rptr->coeff=pptr->coeff;
                rptr->exp=pptr->exp;
                rptr->link=NULL;
                pptr=pptr->link;
        }
        while(qptr!=NULL)
        {
                new=(NODE*)malloc(sizeof(NODE));
                rptr->link=new;
                rptr=new;
                rptr->coeff=qptr->coeff;
                rptr->exp=qptr->exp;
                rptr->link=NULL;
                qptr=qptr->link;
        }
        printf("\nThe first polynomial is\n");
        display(1);
        printf("\nThe second polynomial is\n");
        display(2);
        printf("\nThe sum of the polynomials is\n");
        display(3);
}
                                    
