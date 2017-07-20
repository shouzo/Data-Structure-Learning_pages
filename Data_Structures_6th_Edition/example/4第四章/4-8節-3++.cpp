/*=========================================================

     4-8�` ��4.6: ���j : �e������D

	  hanoi()   �� n �ӽL�l,�q form �W,�g�� by �W,�h�� to �W

  =========================================================
*/
#include <cstdlib>
#include <iostream>

using namespace std;

void hanoi(int , char , char , char );

int main(int argc, char *argv[])
{
    int n;
    
	cout << "Please input number => ";
    cin >> n;                     //Ū�J�Ʀr

    if(n > 20) 			
    {					
		cout << "The calucation time will be too long to wait...";
		return !EXIT_SUCCESS;
    }
    if(n < 0)				//�p��s���Ƥ��X�k
    {
		cout << "input error,number must > 0";
		return !EXIT_SUCCESS;
    }
    hanoi(n,'A','B','C');
    cout << "����\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*�� n �ӽL�l,�q form �W,�g�� by �W,�h�� to �W*/
void hanoi(int n, char from, char by, char to)
{
    if(n > 0)
    {
		hanoi(n-1, from, to, by);
		cout << "move disk no. " << n << " from " << from << " to " << to << "\n" ;
		hanoi(n-1, by, from, to);
    }
}
