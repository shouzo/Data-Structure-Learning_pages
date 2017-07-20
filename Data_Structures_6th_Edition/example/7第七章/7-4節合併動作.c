/*=========================================================

       7-4�` �X�ְʧ@

          merge()				�X��
          a[M]					���X�֤����1
		  b[N]					���X�֤����2
          c[M+N]				�X�֪����G

  =========================================================
*/

#include    <stdio.h>
#include	<stdlib.h>

#define M	5
#define	N	7
void  merge(int [], int [], int , int [], int );

int main(int argc, char *argv[])
{
   int a[M]={9,12,17,21,37},i;
   int b[N]={3,11,20,55,67,71,89};
   int c[M+N];

   printf("�}�C A :\n");
   for(i=0;i < M ;i++)
        printf(" %d",a[i]);
   printf("\n�}�C B :\n");
   for(i=0;i < N ;i++)
        printf(" %d",b[i]);
   merge(c, a, M, b, N);

   printf("\n�X�֦� �}�C C :\n");
   for(i=0;i < M+N ;i++)
        printf(" %d",c[i]);
   printf("\n");
   system("PAUSE");
   return EXIT_SUCCESS;
}

void 	merge(int c[], int a[], int m, int b[], int n)
{	int	i, j, k;

    i = j = k = 0 ;
	for (; i < m && j < n ; k++)
		c[k] = ( a[i] <= b[j]) ? a[i++] : b[j++] ;
	for (; i < m ;)
		c[k++] = a[i++] ;
	for (; j < n ;)
		c[k++] = b[j++] ;
}
