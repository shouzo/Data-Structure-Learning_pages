/*=========================================================

      4-8¸` »¼°j : factor

	  fact() 	¶¥¼h¨ç¦¡

   
  =========================================================
*/
#include <cstdlib>
#include <iostream>

using namespace std;

int fact(int);

int main(int argc, char *argv[])
{
    int n;
    
    cout << "Please input a number less than 12 => ";
    cin >> n;                     //Åª¤J¼Æ¦r

    if(n > 12)			
    	cout << "The number is too large ...";
	
	else
		cout << n << "! = " << fact(n) << " \n ";

    system("PAUSE");
    return EXIT_SUCCESS;
}

int fact( int n)
{
    int	 f;
    if ( n==0) return ( 1 );	//²×¤î±ø¥ó
    f = fact(n-1);				//»¼°j©I¥s
    return ( n * f );
}
