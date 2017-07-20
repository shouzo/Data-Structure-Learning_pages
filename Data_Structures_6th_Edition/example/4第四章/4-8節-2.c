/*=========================================================

     4-8節 例 4.5  遞迴
	 
	  Fib() 	Fibanacci數列函式
   
  =========================================================
*/
#include<stdio.h>
#include <stdlib.h>

int   Fib( int );

int main(int argc, char *argv[])
{
    int n;
    
	printf("Please input an integer  =>");
    scanf("%d",&n);                     /*讀入數字*/

	if ( n < 0 )
		printf("Wrong Input");
	else
		printf("Fib(%d) = %d \n ",n,Fib(n));
    
    system("PAUSE");	
    return 0;
}

int   Fib( int n)
{
	int   i, j;
	if ( n==0 ) return 0;
	if ( n==1 ) return 1;
	i = Fib(n-1);
	j = Fib(n-2);
	return (i+j);
}
