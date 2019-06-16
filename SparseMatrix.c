#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

void delay(unsigned int ms)//for producing time delays wherever required
{
    clock_t goal=ms+clock();
    while(goal>clock());
}


void SetColorAndBackground(int ForgC,int BackC)//for setting the colours in the gui
{

WORD wColor=((BackC & 0x0F) << 4)+(ForgC & 0x0F);;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
return;

}





COORD coordinate={0,0};
void gotoxy(int x,int y)//for moving the cursor to wherever required
{
    coordinate.X=x;
    coordinate.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
}


//defining the structure of the bag
typedef struct node
{
    char data[10];
    int count;
    struct node *link;
}NODE;

//funtcion to insert an element into the bag
void insert(NODE *header)
{
    NODE *ptr,*n;
    int flag;
    char data[10];
    ptr=header;
    flag=0;
    system("cls");
    SetColorAndBackground(9,15);

    gotoxy(30,18);

    printf("Enter the element to be inserted: ");
    gotoxy(64,18);
    printf("{ ");


    scanf(" %s",data);
    gotoxy(67,18);
    printf("}");

    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
        if(strcmp(ptr->data,data)==0)//if the item is already present in the bag
        {
            flag=1;
            goto increment;
        }

    }
    if(flag==0)//item is not already present in the bag, so new node is created
    {
        n=(NODE*)malloc(sizeof(NODE));
        strcpy(n->data,data);
        n->count=1;
        n->link=NULL;
        ptr->link=n;
        gotoxy(30,21);
        printf("%s inserted",data);
    }
    else//item is already present in the bag, so its count is incremented by 1
    {
        increment:
        ptr->count++;
        gotoxy(30,24);
        printf("%s inserted",data);
    }

//goto hello;
}

//function to delete an element from the bag
void delete1(NODE *header)
{
    NODE *ptr,*ptr1;
    int flag=0;
    char data[5];
    system("cls");
    SetColorAndBackground(9,15);

    ptr=header;
    gotoxy(30,18);
    printf("Enter the element to be deleted: ");
    //gotoxy(60,23);
    scanf(" %s",data);
    if(ptr==NULL)
    {
        gotoxy(30,20);
        printf("The bag is empty");
    }
    else
    {
        while(ptr->link!=NULL)//traversing through the list
        {
            ptr1=ptr;
            ptr=ptr->link;
            if(strcmp(ptr->data,data)==0)//searching for the item
            {
                flag=1;
                break;
            }

        }
        if(flag==0)//item was not encountered
        {
            gotoxy(30,21);
                printf("%s is not present in the bag",data);
        }
        else//item was found in the bag
        {
            (ptr->count)--;
            gotoxy(30,21);
            printf("One %s has been deleted from the bag",data);
            if(ptr->count==0)//if the item was the last of its kind
            {
                gotoxy(30,23);
        printf("There are no %s's remaining in the bag",data);
                ptr1->link=ptr->link;
                free(ptr);
            }
            else
            {
                gotoxy(25,23);
                printf("There is/are %d %s's remaining in the bag",ptr->count,data);
            }
        }
    }
  //  goto hello;
}
void display(NODE *header)
{
    NODE *ptr;
    char data[10];
    int i;
    SetColorAndBackground(9,15);
    ptr=header->link;
    system("cls");
    if(ptr==NULL)
    {
        gotoxy(40,19);
        printf("The bag is empty");
    }
    else
    {   //
        gotoxy(40,19);
        printf("The bag is:{");
        while(ptr!=NULL)//traversing till the end of the list
        {
            if(header->link==ptr)
                {
                    printf("%d%s",ptr->count,ptr->data);
                }
            else
                {
                    printf(",%d%s",ptr->count,ptr->data);
                }

            ptr=ptr->link;

        }
        //


        printf("}");
    }
}

//function for displaying credits
void end()
{    int i;
    SetColorAndBackground(9,15);
    for(i=1;i<40;i++)
    {
        system("cls");
        gotoxy(35,3);
        printf("DEVELOPERS OF THIS PROGRAM......");
        gotoxy(i+6,8);
        printf("NANDAGOPAL");
        gotoxy(84-i,10);
        printf("SARATH");
        gotoxy(i+6,12);
        printf("SIDHARTH");
        gotoxy(84-i,14);
        printf("VIVEK");
        delay(30);

    }
}



int main()
{
    NODE *header;//header node to the bag
    int i, ch;//i-loop variable,ch-user's choice
    char data[10];
    header=(NODE*)malloc(sizeof(NODE));
    //assigning header with NULL value
    strcpy(header->data,"NULL");
    header->count=0;
    header->link=NULL;
    SetColorAndBackground(9,15);

    system("cls");
    while(1)//continue execution until user manually exits
    {
        gotoxy(35,4);//menu of the program
        printf("Bag/multiset implementation using linked list");
        gotoxy(40,8);
        printf("1. Insert an element into the bag");
        gotoxy(40,9);
        printf("2. Delete an element from the bag");
        gotoxy(40,10);
        printf("3. Display the elements of the bag");
        gotoxy(40,11);
        printf("4. Exit");
        gotoxy(40,12);
        printf("5. Know the Developers");
        gotoxy(40,16);
        printf("your choice:");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1: insert(header);
                    getchar();
                    break;

            case 2: delete1(header);
                    getchar();
                     break;

            case 3: display(header);
                    getchar();
                    break;

            case 4: exit(0);
                    break;
            
            case 5: end();
                    
                    break;
            
            default :printf("Wrong input");


        };
     }
    return 0;
}
