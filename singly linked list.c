#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void create();
void insert_atfirst();
void insert_atlast();
void insert();
void delete_bypos();
void delete_byval();
void display();
int menu();
struct node
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL,*temp=NULL;
void main()
{
    int ch;
    clrscr();
    do{
        ch=menu();
 
        switch(ch)
        {
            case 1:create();
                break;
            case 2:insert_atfirst();
                break;
            case 3:insert_atlast();
                break;
            case 4:insert();
                break;
            case 5:delete_bypos();
                break;
            case 6:delete_byval();
                break;
            case 7:display();
                break;
            case 8:exit(0);
            case 9:clrscr();
            default:printf("\nError-->Enter a valid choice!!");
                exit(0);
        }
    }while(1);
}
 
void create()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Data in the Node:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=temp;
    }
    else
    {
        last->next=temp;
        last=temp;
    }
}
 
void insert_atfirst()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Element:");
    scanf("%d",&temp->data);
    temp->next=first;
    first=temp;
}
void insert()
{
    struct node *t, *t1;
    int pos, count=1,AB;
    printf("\nEnter Position to be inserted:");
    scanf("%d",&pos);
    printf("\nAfter[1] or Before[2]:");
    scanf("%d",&AB);
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    t=t1=first;
    while(t!=NULL)
    {
        if(pos==count)
            break;
        else
        {
            t=t1;
            t=t->next;
            count++;
        }
    }
    if(AB==1)
    {
        temp->next=t->next;
        t->next=temp;
    }
    else if(AB==2)
    {
        temp->next=t;
        t1->next=temp;
    }
    else
        printf("\nInvalid Input");
}
 
void insert_atlast()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter value to be inserted at last:");
    scanf("%d",&temp->data);
    last->next=temp;
    last=temp;
}
 
void delete_bypos()
{
    struct node *t,*t1;
    int pos, count=1;
    printf("\nEnter the Position of the element you would like to delete:");
    scanf("%d",&pos);
    t=t1=first;
    while(t!=NULL)
    {
        if(pos==count)
        t1=t;
        t=t->next;
        count++;
    }
    if(pos==1)
    {
        first=t->next;
        printf("\nExceuted-->First Node is deleted!!");
    }
    else if(t==last)
    {
        t1->next=NULL;
        free(t);
        printf("\nExecuted-->Last Node is deleted!!");
    }
    else
    {
        t1->next=t->next;
        free(t);
        printf("\nExecuted-->Node has been deleted!!");
    }
}
 
void delete_byval()
{
    int val, count=1;
    struct node *t,*t1;
    printf("\nEnter value:");
    scanf("%d",&val);
    t=t1=first;
    while(t!=NULL)
    {
        if(val==t->data)
        break;
        else
        {
        t=t->next;
        count++;
        }
    }
    if(t==first)
    {
        first=t->next;
        free(t);
    }
    else if(first==last)
    {
        t1->next=NULL;
        free(t);
        last=t1;
    }
    else
    {
        t1->next=t->next;
        free(t);
    }
}
void display()
{
    temp=first;
    while(temp!=NULL)
    {
    printf("|%d|%d| --> ",temp->data,temp->next);
    temp=temp->next;
    }
}
 
int menu()
{
    int ch;
    printf("\n------------");
    printf("\nSingle Linked List");
    printf("\n------------");
    printf("\n1.Create\n2.Insert at first\n3.Insert at last\n4.Insert at Middle\n5.Delete by Position\n6.Delete by Value\n7.Display\n8.Exit");
    printf("\n\n-->Enter Your Choice:");
    scanf("%d",&ch);
    return ch;
}