/*=========================================================

     4-8�` �� 4.5  ���j
	 
	  Fib() 	Fibanacci�ƦC�禡
   
  =========================================================
*/
#include <cstdlib>
#include <iostream>

using namespace std;


int   Fib( int );

int main(int argc, char *argv[])
{
    int n;
    
	cout << "Please input an integer  =>";
    cin >> n;                     /*Ū�J�Ʀr*/

	if ( n < 0 )
		cout << "Wrong Input";
	else
		cout << "Fib(" << n << ") = " << Fib(n) << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
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
