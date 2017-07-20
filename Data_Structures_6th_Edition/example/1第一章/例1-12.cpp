/*=========================================================

     �� 1-12

        factorial()       �D N ����
  =========================================================
*/

#include <cstdlib>
#include <iostream>
using namespace std;

int factor(int);

int main(int argc, char *argv[])
{
    int n;
    int answer;

    cout << "Please input a number no bigger than 12 => ";
    cin >> n;                     //Ū�J�Ʀr

    if(n > 12)                  //�]�j��12�������W�X int �ү��ܤ��d��
        cout << "The answer will be too large for a long integer.\n";
        
    else if(n < 0)                           //�p��s���Ƥ��X�k
        cout << "Input error,number must > 0";
    else
	{
		answer = factor(n);
		cout << answer << "! = " << answer << "\n ";
	}
    system("PAUSE");
    return EXIT_SUCCESS;

}

//�����p��禡        
int factor(int n)
{
    int i;
    int result;

    result=1;
    i=1;
    while(i <= n)
    {
        result=result*i;
        i++;
    }
    return result;
}
