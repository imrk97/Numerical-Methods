#include<stdio.h>
#define N 100
void main()
{
 float x[N],y[N],res,ans=0.0,givX;
 int n,i,j;
 printf("\n Enter the total number of points: ");
 scanf("%d",&n);

 printf("\n\n Enter Values of x");
 for(i=0;i<n;i++)
  {
    printf("\n Enter x%d : ",(i+1));
    scanf("%f",&x[i]);
  }

 printf("\n\n Enter the value of y");
 for(i=0;i<n;i++)
  {
     printf("\n Enter y%d : ",(i+1));
     scanf("%f",&y[i]);
  }

 printf("\n\n\n Enter the value of x to find: ");
 scanf("%f",&givX);

 for(i=0;i<n;i++)
 {
   res=1;
   for(j=0;j<n;j++)
    {
      if(i!=j)
      res=res*(givX-x[j])/(x[i]-x[j]);
    }
   ans=ans+res*y[i];
 }

 printf("\n\n Answer=%8.4f\n",ans);
}
