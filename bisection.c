

#include<stdio.h>

double func(double x)
{
    return 2-x*x ;
}

double e=0.01;
double c;

void bisection(double a,double b)
{
    if(func(a) * func(b) >= 0)
    {
        printf("Incorrect a and b");
        return;
    }

    c = a;

    while ((b-a) >= e)
    {
        c = (a+b)/2;
        if (func(c) == 0.0){
            printf("Root = %lf\n",c);
            break;
        }
        else if (func(c)*func(a) < 0){
                printf("Root = %lf\n",c);
                b = c;
        }
        else{
                printf("Root = %lf\n",c);
                a = c;
        }
    }
}

int main()
{
    double a,b;
    printf(" ***** The function used is 2- x^2 *****\n");
    printf("\n\n Enter Value of a: ");
    scanf("%lf", &a);
    printf("\n Enter Value of b: ");
    scanf("%lf", &b);

    printf("a = %lf\n",a);
    printf("b = %lf\n\n",b);
    bisection(a,b);
    printf("\n");
    printf("Accurate Root calculated is = %lf\n",c);

    return 0;
}
