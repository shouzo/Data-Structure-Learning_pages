/*=========================================================

     ���D 1-12

        factorial()       �D n ����
  =========================================================
*/

#include <stdio.h>

int factorial(int);

int main(int argc, char *argv[])
{
    int n;
    int answer;

    printf("\nPlease input a number no bigger than 12 =>");
    scanf("%d",&n);                     /*Ū�J�Ʀr*/

    if(n > 12)            /*�]�j��12�������|�W�X int �ү��ܤ��d��*/
        printf("The answer will be too large for an integer.\n");
        
    else if(n < 0)                           /*�p��s���Ƥ��X�k*/
        printf("Input error,number must > 0");
    else
	{
		answer = factorial(n);
		printf("%d! = %d\n ",n,answer);
	}
	system("PAUSE");
    return 0;

}

/*�����p��禡*/        
int factorial(int n)
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
