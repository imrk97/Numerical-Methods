
#include<stdio.h>
#include<math.h>
float y(float x)
{
return(1/(1+x*x));
}
void main()
{
float x0,xn,h,s,res;
int i,n;
printf("enter x0,xn and number of intervals\n");
scanf("%f%f%d",&x0,&xn,&n);
h=(xn-x0)/n;
s=y(x0)+y(xn);
for(i=1;i<=(n-1);i++)
{
s+=2*y(x0+i*h);
}
res=h/2*s;
printf("\nthe value of the interval is %f",res);
}
