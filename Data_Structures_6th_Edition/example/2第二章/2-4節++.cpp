/*=========================================================
    String
  =========================================================
*/

#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

#define MAX_LEN	255

int		strlen1( char []);
void	strcpy1( char [], char []);
void	strcpy2( char [], char []);
void	strcpy3( char [], char []);
int		strcmp1( char [], char []);
void	substr1( char [], char [], int , int  );

int main(int argc, char *argv[])
{
	char S1[MAX_LEN], S2[MAX_LEN];
	int len, result, start;
	char choice = '1';
	
	while (choice != '7')
	{
          cout << "\n 1. Count the length of a string.";
          cout << "\n 2. Copy a string by strcpy1.";
          cout << "\n 3. Copy a string by strcpy2.";
          cout << "\n 4. Copy a string by strcpy3.";
          cout << "\n 5. String Comparison.";
          cout << "\n 6. Get substring.";
          cout << "\n 7. Quit.";
          
          cout << "\n Please input your choice: ";
          choice = getche();
          
          switch (choice)
          {
          case '1': /* Test string length*/ 
               cout << "\n Please Input a string => ";
	           cin.getline(S1,MAX_LEN);
	           len = strlen1(S1);
	           cout << "\n The length of string  '" << S1 << "' is " << len << " character(s) \n";
	           break;
   
          case '2': /* Test string length 1 */
	           cout << "\n Please Input a string => ";
	           cin.getline(S1,MAX_LEN);
	           strcpy1(S2,S1);
	           cout << "\n The clone string is  " << S2;
	           break;
   
          case '3': /* Test string length 2*/
	           cout << "\n Please Input a string => ";
               cin.getline(S1,MAX_LEN);
	           strcpy2(S2,S1);
	           cout << "\n The clone string is  " << S2;
	           break;
 
          case '4': /* Test string length 3 */
	           cout << "\n Please Input a string => ";
	           cin.getline(S1,MAX_LEN);
	           strcpy3(S2,S1);
	           cout << "\n The clone string is  " << S2;
	           break;

          case '5':/* Test string comparison */
	           cout << "\n Please Input string 1 =>";
               cin.getline(S1,MAX_LEN);
               cout << "\n Please Input string 2 =>";
	           cin.getline(S2,MAX_LEN);
	           result = strcmp1(S1,S2);
	           switch ( result )
	           {
	           case 0:	cout << "\n "  << S1 << " = " << S2 ;
			        break;
               case 1:	cout << "\n "  << S1 << " < " << S2;
			        break;
	           case -1:cout << "\n "  << S1 << " > " << S2;
			        break;
	           }
	           cout << "\n";
	           break;

          case '6':/* Test sub string */
               cout << "\n Please Input string => ";
               cin.getline(S1,MAX_LEN);
               cout << "\n Please Input start position and length like 5 9 => ";
               cin >> start >> len;
               substr1(S2,S1,start,len);
               cout << "\n Substring is " << S2 << "\n";
               break;
               
          default:
               break;
          }
    }
	
    cout << "\n\n";               
    system("PAUSE");
    return EXIT_SUCCESS;
  
}

int	strlen1( char S[])
{
	int    len ;
	for ( len = 0; S[len] != '\0'; len++) ;
	return ( len ) ;
}

void	strcpy1( char S1[], char S2[])
{
	int  i ;
	for ( i = 0; S2[i] != '\0'; i++) 
	     S1[i] = S2[i] ;
	S1[i] = '\0' ;
}
void	strcpy2( char S1[], char S2[])
{
	int   i ;
	for ( i = 0; (S1[i]=S2[i]) != '\0' ;  i++) ;
}
void	strcpy3( char S1[], char S2[])
{
	for ( ; (*S1 = *S2) != '\0' ; S1++,S2++) ;
}

int   strcmp1( char S1[], char S2[])
{
      int   i ;
      for ( i = 0; S1[i] ==S2[i]; i++) 
	    if (S1[i]=='\0' && S2[i] =='\0')  return 0;
      if ( S1[i] > S2[i])
	    return (-1) ;
      else
	    return (1) ;
}
void	substr1( char S1[], char S[], int i, int n )
{
	int  len, end, j ,k ;

	len = strlen1( S ) ;
	end = i + n ;
	if ( (end>len) || ( n==0))
	      end = len ;
	for ( j = i, k=0 ; j < end ; j++, k++)
	      S1[k]= S[j];
	S1[k] = '\0' ;
}
