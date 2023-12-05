#include<stdio.h>
#include<math.h>

#define MAX 10

int determ(int a[MAX][MAX],int n);

int main()
{
    int i,j,r,c,a[MAX][MAX],b[MAX][MAX],det=0;
    printf("\nMatrisin satir sayisi: ");
    scanf("%d",&r);
    printf("\nMatrisin sutun sayisi: ");
    scanf("%d",&c);
    if(r==c)
    {
       printf("\nMatrisin elemanlarini giriniz:\n");
       for(i=0;i<r;i++)
       {
          for(j=0;j<c;j++)
          {
             scanf("%d",&a[i][j]);
          }
       }
       det=determ(a,r);
       printf("\nVerilen matris:\n");
       for(i=0;i<r;i++)
       {
          for(j=0;j<c;j++)
          {
             printf("%d\t",a[i][j]);
          }
          printf("\n");
       }
       printf("\nMatrisin determinanti: %d\n",det);
    }
    else
    {
       printf("\nDeterminant hesaplanamadi! Matrisin satir ve sutun sayilari esit olmali.\n");
    }
    return 0;
}


int determ(int a[MAX][MAX],int n)
{
  int det=0,p,h,k,i,j,temp[MAX][MAX];
  if(n==1)
  {
      return a[0][0];
  }
  else if(n==2)
  {
      det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
      return det;
  }
  else
  {
    for(p=0;p<n;p++)
    {
       h = 0;
       k = 0;
       for(i=1;i<n;i++)
       {
         for( j=0;j<n;j++)
         {
            if(j==p)
                {
                    continue;
                }
                temp[h][k] = a[i][j];
            k++;
                if(k==n-1)
                {
                      h++;
                      k = 0;
            }
             }
       }
       det=det+a[0][p]*pow(-1,p)*determ(temp,n-1);
    }
    return det;
  }
}