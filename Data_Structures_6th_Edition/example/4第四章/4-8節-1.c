/*=========================================================

      4-8¸` »¼°j : 

	  fact() 	¶¥¼h¨ç¦¡

   
  =========================================================
*/
#include<stdio.h>
#include <stdlib.h>

int fact(int);

int main(int argc, char *argv[])
{
    int n;
    
    printf("Please input a number less than 12 =>");
    scanf("%d",&n);                     /*Åª¤J¼Æ¦r*/

    if(n > 12)			
    	printf("The number is to large ...");
	
	else
		printf("%d! = %d \n ",n,fact(n));
		
    system("PAUSE");	
    return 0;
}

int fact( int n)
{
    int	 f;
    if ( n==0) return ( 1 );	//²×¤î±ø¥ó
    f = fact(n-1);				//»¼°j©I¥s
    return ( n * f );
}
