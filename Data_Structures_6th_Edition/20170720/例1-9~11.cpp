/*=========================================================

     �� 1-9,1-10,1-11

       �j��p��
  =========================================================
*/

#include <iostream.h>

int main(int argc, char *argv[])
{
    int i, j, n, result ;
    
    cout << "Please input a positive integer N => ";
    cin >> n;                     //Ū�J�Ʀr

	// ��h�j�� 
	result = 0 ;
    for (i = 1 ; i <= n ; i++) 
		result = result + 1; 
		
	cout << "\n��h�j�� ";
	cout << "\n result = 0 ;";
    cout << "\n for (i = 1 ; i <= n ; i++) ";
	cout << "\n	result = result + 1; ";
	cout << "\n �� n = "<< n << " ��";
	cout << "\n result = " << result << " ( = " << n << "  )  ";

	// ��h�j��, ����T�w����
	result = 0 ;
	for (i = 1; i <= n ; i ++) 
		for (j = 1 ; j < n ; j++) 	
			result = result + 1 ; 
	
    cout << "\n\n���h�j��, ����T�w���� ";
	cout << "\n result = 0 ;"; 
	cout << "\n for (i = 1; i <= n ; i ++) ";
	cout << "\n	 for (j = 1 ; j < n ; j++)  ";	
	cout << "\n		result = result + 1 ; ";
	cout << "\n �� n = "<< n << " ��";
    cout << "\n result = " << result << " ( = " << n << " * ( " << n << " - 1 " << ") )";

	// ��h�j��, ����T�w����
	result = 0 ;
	for (i = 1 ; i <= n ; i++) 
		for (j = i+1 ; j <= n ; j++) 	
			result = result + 1; 
	
    cout << "\n\n���h�j��, ���餣�T�w���� ";
	cout << "\n result = 0 ;"; 
	cout << "\n for (i = 1; i <= n ; i ++) ";
	cout << "\n	 for (j = i+1 ; j <= n ; j++)  ";	
	cout << "\n		result = result + 1 ; ";
	cout << "\n �� n = "<< n << " ��";
    cout << "\n result = " << result << " ( = " << n << " * ( " << n << " - 1 ) / 2 ) \n";	
	system("PAUSE");
    return EXIT_SUCCESS;

}

