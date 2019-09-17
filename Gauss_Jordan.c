#include <stdio.h>
#include<math.h>

#define MATRIX_DIMENSION 4

float pfMatr[MATRIX_DIMENSION * MATRIX_DIMENSION]=
 {
  10.0, -7.0, 3.0, 5.0,
  -6.0, 8.0, -1.0,-4.0,
  3.0, 1.0, 4.0, 11.0,
  5.0, -9.0, -2.0, 4.0,
 };

float pfVec[MATRIX_DIMENSION]={6.0, 5.0, 2.0, 7.0};

float pfSolution[MATRIX_DIMENSION];

void VectorPrint()
 {
  int i;
  for(i=0;i<MATRIX_DIMENSION;i++)
   {
     printf("%9.2f\t",pfSolution[i]);
   }
 }

int gausselimination()
 {
  float fMaxElem;
  float fACC;

  int i, j , k ,m;
 
 for(k=0;k<(MATRIX_DIMENSION-1);k++)
  {
   fMaxElem=fabs(pfMatr[k * MATRIX_DIMENSION + k]);
   m=k;
   for(i=k+1; i<MATRIX_DIMENSION;i++)
   {
    if(fMaxElem < fabs(pfMatr[i * MATRIX_DIMENSION + k]))
    {
     fMaxElem = pfMatr[i * MATRIX_DIMENSION + k];
     m=i;
    }
   }

   if(m!=k)
   {
    for(i=k;i<MATRIX_DIMENSION; i++)
     {
      fACC=pfMatr[k * MATRIX_DIMENSION + i];
      pfMatr[k * MATRIX_DIMENSION + i]= pfMatr[m * MATRIX_DIMENSION + i];
      pfMatr[m * MATRIX_DIMENSION + i] = fACC;
     }
    fACC = pfVec[k];
    pfVec[k] = pfVec[m];
    pfVec[m] = fACC;
   }

   if(pfMatr[k * MATRIX_DIMENSION + k]==0.)
    return 1;
   for(j=(k+1);j<MATRIX_DIMENSION;j++)
    {
     fACC= -pfMatr[j * MATRIX_DIMENSION + k] / pfMatr[k * MATRIX_DIMENSION + k];
     for(i=k;i<MATRIX_DIMENSION;i++)
     {
       pfMatr[j * MATRIX_DIMENSION + i]=pfMatr[j * MATRIX_DIMENSION + i] + fACC * pfMatr[k * MATRIX_DIMENSION + i];
     }
    pfVec[j]=pfVec[j] + fACC * pfVec[k];
    }
  }

  for(k=(MATRIX_DIMENSION - 1);k>=0;k--)
  {
	pfSolution[k]=pfVec[k];
	for(i=(k+1);i<MATRIX_DIMENSION;i++)
     {
      pfSolution[k] =(pfMatr[k * MATRIX_DIMENSION + i] * pfSolution[i]);
     }
    pfSolution[k]=pfSolution[k]/pfMatr[k * MATRIX_DIMENSION + k];
  }
  return 0;
}

int main()
 {
  int res;
  res=gausselimination();
  if(res)
   {
     printf("No solution!\n");
     return 1;
   }
  else
   {
     printf("Solution:\n");
     VectorPrint();
   }
  return 0;
}




