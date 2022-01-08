#include<stdio.h>
#include<stdlib.h>
void printsparse(int b[][3])
{
 int i,n;
n=b[0][2]; 
printf("\nAfter Transpose:\n");
printf("\nrow\t\tcolumn\t\tvalue\n");
for(i=0;i<=n;i++)
printf("%d\t\t%d\t\t%d\n",b[i][0],b[i][1],b[i][2]);
}
void transpose(int sp[][3],int c[][3])
{
  int i,j,k,n;
  c[0][0]=sp[0][1];
  c[0][1]=sp[0][0];
  c[0][2]=sp[0][2];
  k=1;
  n=sp[0][2];
  for(i=0;i<sp[0][1];i++)
  for(j=1;j<=n;j++)
  if(i==sp[j][1])
  {
  c[k][0]=i;
  c[k][1]=sp[j][0];
  c[k][2]=sp[j][2];
  k++;
}
}
int main()
{
	int sp[100][3],sp1[100][3],add[100][3], a[100][100],b[100][100],c[100][3],n,m,num=0,num1=0,i,j,l,z,x,y,tot,op;
	printf("Enter the rows and coloumn of your matrix:");
	scanf("%d %d",&n,&m);
	l=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("\nEnter the (%d,%d) Element first matrix:",i, j);
			scanf("%d", &a[i][j]);
			if(a[i][j]!=0)
			{	
				num++;
				sp[l][0]=i;
				sp[l][1]=j;
				sp[l][2]=a[i][j];
				l++;
			}
			
		}
	}
	
	sp[0][0]=n;
	sp[0][1]=m;
	sp[0][2]=num;
	printf("\n First triplet matrix");
	for(x=0;x<=num;x++)
	{
		printf("\n");
		for(y=0;y<3;y++)
		{
				printf("%d\t",sp[x][y]);
		}
	}
	l=1;
	for(i=0;i<n;i++)
	{   for(j=0;j<m;j++)
		{
			printf("\nEnter the (%d,%d) Element of second matrix:",i, j);
			scanf("%d", &b[i][j]);
			if(b[i][j]!=0)
			{	
				num1++;
				sp1[l][0]=i;
				sp1[l][1]=j;
				sp1[l][2]=b[i][j];
				l++;
			}
			
		}
	}
	sp1[0][0]=n;
	sp1[0][1]=m;
	sp1[0][2]=num1;
	printf("\n Second triplet matrix");
	for(x=0;x<=num1;x++)
	{
		printf("\n");
		for(y=0;y<3;y++)
		{
				printf("%d\t",sp1[x][y]);
		}
	}
	while(1)
        { printf("\nEnter the choice\n1.Addition\n2.Transpose\n3.Exit\n");
          scanf("%d",&op);
          switch(op)
          { case 1: z=1;
	    add[0][2]=0;
	    add[0][0]=n;
	    add[0][1]=m;
	    i=1;
	    tot=num+num1;	
	    while(i<=tot)
	    {if((sp[i][0]==sp1[i][0] && sp[i][1]==sp1[i][1]))
	     {	add[z][0]=sp[i][0];
		add[z][1]=sp[i][1];
		add[z][2]=sp[i][2]+sp1[i][2];
		z++;
		tot--;
	     }
	     else if(sp[i][0]<sp1[i][0])
	     {  add[z][0]=sp[i][0];
		add[z][1]=sp[i][1];
		add[z][2]=sp[i][2];	
		z++;
		add[z][0]=sp1[i][0];
		add[z][1]=sp1[i][1];
		add[z][2]=sp1[i][2];	
		z++;
	     }
	     else if(sp[i][0]>sp1[i][0])
	     {  add[z][0]=sp1[i][0];
		add[z][1]=sp1[i][1];
		add[z][2]=sp1[i][2];
		z++;
		add[z][0]=sp[i][0];
		add[z][1]=sp[i][1];
		add[z][2]=sp[i][2];
		z++;
				
	     }
	     else if(sp[i][1]<sp1[i][1])
	     {  add[z][0]=sp[i][0];
		add[z][1]=sp[i][1];
		add[z][2]=sp[i][2];
		z++;
		add[z][0]=sp1[i][0];
		add[z][1]=sp1[i][1];
		add[z][2]=sp1[i][2];
		z++;
	     }
	     else if(sp[i][1]>sp1[i][1])
	     {  add[z][0]=sp1[i][0];
		add[z][1]=sp1[i][1];
		add[z][2]=sp1[i][2];
		z++;	
	        add[z][0]=sp[i][0];
		add[z][1]=sp[i][1];
		add[z][2]=sp[i][2];
		z++;	
				
	     }
	     i++;	
	    }
	    add[0][2]=tot;
	    printf("\n\n ADDED TRIPLET MATRIX");
	    for(x=0;x<=tot;x++)
	      {
		printf("\n");
		for(y=0;y<3;y++)
		{
		 printf("%d\t",add[x][y]);
		}
	      }
	       break;
	case 2:printf("Transpose of first sparse matrix");
	       transpose(sp,c);
	       printsparse(c);
	       printf("Transpose of second sparse matrix");
	       transpose(sp1,c);
	       printsparse(c);
	       break;
	case 3:exit(1);       
    }
  }
} 
