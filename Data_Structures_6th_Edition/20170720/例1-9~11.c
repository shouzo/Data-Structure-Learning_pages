/*=========================================================

     �� 1-9,1-10,1-11

       �j��p��
  =========================================================
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j, n, result ;
    
    printf("Please input a positive integer N =>");
    scanf("%d",&n);                     /*Ū�J�Ʀr*/

	/* ��h�j�� */
	result = 0 ;
    for (i = 1 ; i <= n ; i++) 
		result = result + 1;
         
	printf("\n��h�j�� ");
	printf("\n result = 0 ;");
    printf("\n for (i = 1 ; i <= n ; i++) ");
	printf("\n	result = result + 1; ");
	printf("\n �� n = %d ��", n);
    printf("\n result = %d ( = %d  )  ",result,n);

	/* ���h�j��, ����T�w����*/
	result = 0 ;
	for (i = 1; i <= n ; i ++) 
		for (j = 1 ; j < n ; j++) 	
			result = result + 1 ; 
			
	printf("\n\n���h�j��, ����T�w���� ");
	printf("\n result = 0 ;"); 
	printf("\n for (i = 1; i <= n ; i ++) ");
	printf("\n	 for (j = 1 ; j < n ; j++)  ");	
	printf("\n		result = result + 1 ; ");
	printf("\n �� n = %d ��", n);
    printf("\n result = %d ( = %d * ( %d - 1 ) ) ",result,n,n);

	/* ���h�j��, ���餣�T�w����*/
	result = 0 ;
	for (i = 1 ; i <= n ; i++) 
		for (j = i+1 ; j <= n ; j++) 	
			result = result + 1; 
			
	printf("\n\n���h�j��, ���餣�T�w���� ");
	printf("\n result = 0 ;"); 
	printf("\n for (i = 1; i <= n ; i ++) ");
	printf("\n	 for (j = i+1 ; j <= n ; j++)  ");	
	printf("\n		result = result + 1 ; ");
	printf("\n �� n = %d ��", n);
	printf("\n result = %d ( = %d * ( %d - 1 ) / 2 ) \n",result,n,n);	
	system("PAUSE");
    return 0;

}

