/*=========================================================

     4-8�` �� 4.7  ���j
	 
	  �G�����Y��
   
  =========================================================
*/
#include <cstdlib>
#include <iostream>

using namespace std;

int	 C(int n, int k);

int main(int argc, char *argv[])
{
    int n,k;
    
	cout << "Please input integers n and k (n>k>0) =>";
    cin >> n >> k;                     /*Ū�J�Ʀr*/

	if ( (n <= 0) || ( k < 0 ) || (n < k))
		cout << "Wrong Input" << endl;
	else
		cout << "C(" << n << "," << k << ") = " << C(n,k) << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

int	 C(int n, int k)
{
	if ( k==0 || n==k ) return 1;			//�פ����
		return 	( C(n-1,k) + C(n-1,k-1) );	//���j�I�s
}
