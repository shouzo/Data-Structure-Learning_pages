/*=========================================================

     4-8�` �� 4.7  ���j
	 
	  �G�����Y��
   
  =========================================================
*/
#include <stdio.h>
#include <stdlib.h>

int	 C(int n, int k);

int main(int argc, char *argv[])
{
    int n,k;
    
	printf("Please input integers n and k (n>k>0) =>");
    scanf("%d %d",&n,&k);                     /*Ū�J�Ʀr*/

	if ( (n <= 0) || ( k < 0 ) || (n < k))
		printf("Wrong Input\n");
	else
		printf("C(%d,%d) = %d \n ",n,k,C(n,k));

    system("PAUSE");	
    return 0;
}

int	 C(int n, int k)
{
	if ( k==0 || n==k ) return 1;			//�פ����
		return 	( C(n-1,k) + C(n-1,k-1) );	//���j�I�s
}
