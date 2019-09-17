# include<stdio.h>
#define N 100
void main()
{
	float x[N],y[N],res,ans=0.0,givX;
	int i,j,n;
	printf("\n\nEnter the total number of points:: ");
	scanf("%d",&n);
	printf("\n Enter  the value of x \n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&x[i]);
		
		}
	printf("Enter the values of y\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&y[i]);
		}
		printf("\n Enter the value of x  to find the corresponding value of y:: ");
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
	printf("\n\n Answer = %8.4f\n",ans);
	}
