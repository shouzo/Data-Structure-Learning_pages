/*=========================================================

      4-8�` ���j : factor

	  fact() 	���h�禡

   
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
    cin >> n;                     //Ū�J�Ʀr

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
    if ( n==0) return ( 1 );	//�פ����
    f = fact(n-1);				//���j�I�s
    return ( n * f );
}
