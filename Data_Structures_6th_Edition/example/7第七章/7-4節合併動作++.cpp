/*=========================================================

       7-4�` �X�ְʧ@

          merge()				�X��
          a[M]					���X�֤����1
		  b[N]					���X�֤����2
          c[M+N]				�X�֪����G

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define M	5
#define	N	7
void  merge(int [], int [], int , int [], int );

int main(int argc, char *argv[])
{
   int a[M]={9,12,17,21,37},i;
   int b[N]={3,11,20,55,67,71,89};
   int c[M+N];

   cout << "�}�C A :" << endl;
   for(i=0;i < M ;i++)
        cout << " " << a[i];
   cout << endl << "�}�C B :" << endl;
   for(i=0;i < N ;i++)
        cout << " " << b[i];
   merge(c, a, M, b, N);

   cout << endl << "�X�֦� �}�C C :" << endl;
   for(i=0;i < M+N ;i++)
        cout << " " << c[i];
   cout << endl;
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
