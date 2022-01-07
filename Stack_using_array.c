/*Write a menu driven C program to implement stack using one
dimensional array*/
#include<stdio.h>
int t=-1,n=10,st[10];
void push();
void pop();
void peek();
void display();
int main()
{ int ch;
  while(1)
  { printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
    printf("Enter Choice:");
    scanf("%d",&ch);
    switch(ch)
    { case 1: push();
              break;
      case 2: pop();
              break;
      case 3: peek();
              break;
      case 4: display();
              break;
      case 5: return 0;
    }
  }
  return 0;
}
void push()
{ int d;
  if(t==n-1)
  {printf("Stack Overflow!!\n");
  }
  else
  { printf("Enter element to be pushed:");
    scanf("%d",&d);
    t=t+1;
    st[t]=d;
  }
}
void pop()
{ if(t==-1)
  {printf("Stack is empty!!\n");
  }
  else
  { printf("Popped element=%d\n",st[t]);
    t=t-1;
  }
}
void peek()
{ if(t==-1)
  { printf("Stack is empty!!\n");
  }
  else
  { printf("Top Element=%d",st[t]);
  }
}
void display()
{ int i;
  if(t==-1)
  {printf("Stack is empty!!\n");
  }
  else
  { printf("Stack=\n");
    for(i=t;i>=0;i--)
    {printf("%d\n",st[i]);
    }
  }
}  
