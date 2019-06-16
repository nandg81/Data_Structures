#include<stdio.h>
#include<stdlib.h>
main()
{
    int A[100],i,j,ch1,ch2,n,temp,min,pos;
    printf("\nProgram to sort an array");    
    while(1)
    {
        printf("\nEnter the size of the array ");
        scanf("%d",&n);
        printf("\nEnter the elements of the array\n");        
        for(i=0;i<n;i++)
        {
            printf("Enter element %d ",i+1);
            scanf("%d",A[i]);
        }
        printf("\nThe array is\n")
        for(i=0;i<n;i++)
        {
            printf("%d ",A[i]);
        }
        printf("\n\nPress\n1. Bubble sort\n2. Selection sort\n3. Insertion sort");
        scanf("%d",&ch1);
        if(ch1==1)
        {
            for(i=0;i<n-1;i++)
            {
                for(j=0;j<n-1-i;j++)
                {
                    if(A[j]>A[j+1])
                    {
                        temp=A[j];
                        A[j]=A[j+1];
                        A[j+1]=temp;
                    }
                }
            }
            printf("\nThe sorted array is\n");
            for(i=0;i<n;i++)
            {
                printf("%d ",A[i]);
            }    
        }
        else if(ch==2)
        {
            for(i=0;i<n-1;i++)
            {
                pos=i;
                min=A[i];
                for(j=i+1;j<n;j++)
                {
                    if(min<A[j])
                    {
                        min=A[j];
                        pos=j;
                    }
                }
                temp=A[i];
                A[i]=A[pos];
                A[pos]=temp;
            }
            printf("\nThe sorted array is\n");
            for(i=0;i<n;i++)
            {
                printf("%d ",A[i]);
            }    
        }
        else if(ch==3)
        {
            for(i=1;i<n;i++)
            {
                temp=A[i];
                j=i-1;
                while((j>=0)&&(A[j]>temp))
                {
                    A[j+1]=A[j];
                    j=j-1;
                }
                A[j+1]=temp;
            }
            printf("\nThe sorted array is\n");
            for(i=0;i<n;i++)
            {
                printf("%d ",A[i]);
            }    
        }
        else
            printf("Wrong input");
        printf("Do you want to sort another array (1-yes, 2-no) ? ");
        scanf*("%d",&ch2);
        ifc(ch==2)
            break;
    }
}   
