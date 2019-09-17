#include<stdio.h>

int fact(int t)
{
  int i,f=1;
  for(i=1;i<=t;i++)
   {
    f=f*i;
   }
  return f;
}

void main()
{
  int i,j,n;
  float x[20],y[20],d[20][20],a,h,u,b,z,k;
  printf("\n Enter the total number of entries: ");
  scanf("%d",&n);
  
  printf("\n\n Enter the value for x: ");
  for(i=0;i<n;i++)
   {
    scanf("%f",&x[i]);
   }
  
  printf("\n\n Enter the value for y: ");
  for(i=0;i<n;i++)
   {
    scanf("%f",&y[i]);
   }
  

  for(i=0;i<=n-2;i++)
   {
    d[i][0]=y[i+1]-y[i];
   }

  for(j=1;j<=n-2;j++)
   {
     for(i=0;i<=n-j-2;i++)
      {
        d[i][j]=d[i+1][j-1]-d[i][j-1];
      }
   }

  for(i=0;i<n-1;i++)
   {
    printf(" %7.3f\t %7.3f",x[i],y[i]);
     for(j=0;j<n-i-2;j++)
      {
       printf("\t%7.3f",d[i][j]);
      }
    printf("\n");
   }

  printf("\n\n Enter the value of x for which y is required: ");
  scanf("%f",&a);
 
  h=x[1]-x[0];
  u=(a-x[n-1])/h;
  k=0.0;
  for(i=0;i<=n-2;i++)
   {
    z=1.0;
    for(j=0;j<=i;j++)
     {
      z=z*(u+j);
     }
    k+=z*d[n-2-i][i],fact(j);
   }
  b=y[n-1]+k;
  printf("\n\n\n The value of y at %f = %f\n",a,b);
}

