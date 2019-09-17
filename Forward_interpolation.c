#include<stdio.h>
#define MAXN 100
#define ORDER 4
void main ()
{    
    float ax[MAXN+1],ay[MAXN+1],diff[MAXN +1][ORDER+1],nr=1.0,dr=1.0,x,p,h,yp;
    int n,i,j,k;
    printf("\n enter the value of n:: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n enter the value of x \n");
        scanf("%f",&ax[i]);
        printf("enter the value of y");
        scanf("%f",&ay[i]);
    }
    printf("\n enter the value of x for which the value of y is wanted \n");
    scanf("%f",&x);
    h=ax[1]-ax[0];
    for(i=0;i<n;i++)
    diff[i][0]=ay[i+1]-ay[i];
    for(j=1;j<n-1;j++)
    for(i=0;i<n-j-1;i++)
    diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
    printf("\n the forward difference table is \n");
    for(i=0;i<n;i++) 
    {
        for(j=0;j<n;j++)
        {
            switch(j)
            {
                case 0:
                printf("%f",ax[i]);
                break;
                case 1:
                printf("%f",ay[i]);
                break;
                default:
                printf("%f",diff[i][j-2]);
            }        
        }    
    
        printf("\n");

    }

    p=(x-ax[0])/h;
    nr=p;
    yp=ay[0]+p*diff[0][0];
    for(i=1;i<n;i++)
    {
        dr*=(i+1);  
        nr*=(p-i);
        yp+=nr*diff[0][i]/dr;
    }
    printf("\n value of x=%f is %f",x,yp);
}





