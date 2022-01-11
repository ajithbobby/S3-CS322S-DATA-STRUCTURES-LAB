#include<stdio.h>
#include<stdlib.h>
int Q[20],Pr[20];
int r=-1,f=-1,N;
void enqueue(int data,int p)
{   int i;
	if((f==0)&&(r==N-1))
		printf("Queue is full");
	else
	{  if(f==-1)
		{ f=r=0;
		  Q[r]=data;
		  Pr[r]=p;
        }
		else if(r == N-1)
		{  for(i=f;i<=r;i++)
		   { Q[i-f]=Q[i];
		     Pr[i-f]=Pr[i];
		     r=r-f;
		     f = 0;
		     for(i=r;i>f;i--)
			 { if(p>Pr[i])
			   { Q[i+1] = Q[i];
				 Pr[i+1] = Pr[i];
			   }
			   else
				 break;
			   Q[i+1] = data;
			   Pr[i+1] = p;
			   r++;
			 }
		    }
		}
		else
		{ for(i=r;i>=f;i--)
		  { if(p>Pr[i])
			{ Q[i+1] = Q[i];
			  Pr[i+1] = Pr[i];	
			}
			else
			  break;
		  }
		  Q[i+1] = data;
		  Pr[i+1] = p;
		  r++;
		}	
	}
}
void print() 
{
int i;
	for(i=f;i<=r;i++)
	{ printf("\nElement = %d\tPriority = %d",Q[i],Pr[i]);
	}
}
int dequeue() 
{   if(f == -1)
	{ printf("Queue is Empty");
	}	
	else
	{ printf("Deleted Element = %d\t Its Priority = %d",Q[f],Pr[f]);
	  if(f==r)
		 f=r=-1;
	  else
		 f++;
	}
}
int main()
{   int op,n,i,data,p;
	printf("Enter Your Choice:-");
	do
	{	printf("\n\n1 Insert Data in Queue\n2 Display Data\n3 Delete data from the Queue\n4 Exit");
		scanf("%d",&op);
		switch(op)
		{  case 1:  printf("\nEnter the number of data");
        		    scanf("%d",&n);
            		printf("\nEnter your data and Priority of data");
            		i=0;
            		while(i<n)
            		{ scanf("%d %d",&data,&p);
            		  enqueue(data,p);
            		  i++;
            		}
        		    break;
           case 2: print();
			       break;
		   case 3: dequeue();
				   break;
		   case 4: exit(0);
			 	   break;
		   default:printf("\nIncorrect Choice");
        }
	}while(op!=0);
    return 0;
}
