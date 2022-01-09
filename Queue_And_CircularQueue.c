/*Write a menu driven C program to implement Queues and Circular
Queue using arrays and perform the following*/
#include<stdio.h>
#include<stdlib.h>
void insert(int qu[],int *f,int *r,int dt,int N)
{
    if(*r==N-1)
     printf("QUEUE OVERFLOW!!\n");
    else if(*f==-1 && *r==-1)
    {
        *f=0;*r=0;
        qu[*r]=dt;
    }
    else
    {
        *r=*r+1;
        qu[*r]=dt;
    }
}
void insertc(int qu[],int *f,int *r,int dt,int N)
{
    if(*f==(*r+1)%N)
        printf("CIRCULAR QUEUE OVERFLOW!!\n");
    else if(*f==-1 && *r==-1)
    {
        *f=0;*r=0;
        qu[*r]=dt;
    }
    else
    {
        *r=(*r+1)%N;
        qu[*r]=dt;
    }
}
void delete(int qu[],int *f,int *r)
{
    if(*r==-1 && *f==-1)
        printf("QUEUE UNDERFLOW!!\n");
    else if(*f==*r)
    {
        printf("Deleted Element: %d\n",qu[*f]);
        *f=-1,*r=-1;
    }
    else
    {
        printf("Deleted Element: %d\n",qu[*f]);
        *f++;
    }
}
void deletec(int qu[],int *f,int *r,int N)
{
    if(*r==-1 && *f==-1)
        printf("QUEUE UNDERFLOW!!\n");
    else if(*f==*r)
    {
        printf("Deleted Element: %d\n",qu[*f]);
        *f=-1,*r=-1;
    }
    else
    {
        printf("Deleted Element: %d\n",qu[*f]);
        *f=(*f+1)%N;
    }
}
void isempty(int *f,int *r)
{
    if(*r==-1 && *f==-1)
        printf("QUEUE IS EMPTY!!\n");
    else
        printf("QUEUE IS NOT EMPTY\n");
}
void isfullc(int *f,int *r,int N)
{
    if(*f==(*r+1)%N)
        printf("QUEUE IS FULL!!\n");
    else
        printf("QUEUE IS NOT FULL\n");
}
void isfull(int *r,int N)
{
    if(*r==N-1)
        printf("QUEUE IS FULL!!\n");
    else
        printf("QUEUE IS NOT FULL\n");
}
void display(int qu[],int *f,int *r)
{   int i;
    if(*r==-1 && *f==-1)
        printf("QUEUE UNDERFLOW!!\n");
    else
    {
        for(i=*f;i<=*r;i++)
        {
        printf("%d\t",qu[i]);
        }
    }
}
void displayc(int qu[],int *f,int *r,int N)
{   int i;
    if(*r==-1 && *f==-1)
        printf("QUEUE UNDERFLOW!!\n");
    else
    {   
        for(i=*f;i<=*r;i=(i+1)%(N+1))
        {
            printf("%d\t",qu[i]);
        }
    }
}
void main()
{
    int c,N,dt,op,t;
    int front=-1,rear=-1,qu[50];
    printf("Select type of Queue:\n");
    printf("1.Queue\n2.Circular\n");
    scanf("%d",&t);
    if(t==1)
            printf("Normal Queue\n");
    else if(t==2)
            printf("Circular Queue\n");
    else
        {   
            printf("!nvalid Input!!\n");
            exit(0);
        }
    printf("Enter Queue limit:\n");
    scanf("%d",&N);
    do
    {
    printf("Menu\n");
    printf("1.Insert\n2.Delete\n3.Is empty\n4.Is full\n5.Display\n6.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            printf("Enter the Element to insert:\n");
            scanf("%d",&dt);
            if(t==1)
            insert(qu,&front,&rear,dt,N);
            else
            insertc(qu,&front,&rear,dt,N);
            break;
        case 2:
            if(t==1)
            delete(qu,&front,&rear);
            else
            deletec(qu,&front,&rear,N);
            break;
        case 3:
            isempty(&front,&rear);
            break;
        case 4:
            if(t==1)
            isfull(&rear,N);
            else
            isfullc(&front,&rear,N);
            break;
        case 5:
            if(t==1)
            display(qu,&front,&rear);
            else
            displayc(qu,&front,&rear,N);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid Input!!\n");
    }
    }
    while(c>=1&&c<=6);
}
