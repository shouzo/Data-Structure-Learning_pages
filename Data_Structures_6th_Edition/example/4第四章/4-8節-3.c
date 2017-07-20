/*=========================================================

     4-8 �`  ��4.6 : ���j : �e������D

	  hanoi()   �� n �ӽL�l,�q form �W,�g�� by �W,�h�� to �W

  =========================================================
*/
#include <stdio.h>
#include <stdlib.h>

void hanoi(int , char , char , char );

int main(int argc, char *argv[])
{
    int n;
    
	printf("Please input number =>");
    scanf("%d",&n);                     /*Ū�J�Ʀr*/

    if(n > 20) 			
    {					
		printf("The calucation time will be too long to wait...");
		return 1;
    }
    if(n < 0)				/*�p��s���Ƥ��X�k*/
    {
		printf("input error,number must > 0");
		return 1;
    }
    hanoi(n,'A','B','C');
    printf("����\n");
    
    system("PAUSE");	
    return 0;
}

/*�� n �ӽL�l,�q form �W,�g�� by �W,�h�� to �W*/
void hanoi(int n, char from, char by, char to)
{
    if(n > 0)
    {
		hanoi(n-1, from, to, by);
		printf("move no. %d  disk from '%c' to '%c' \n",n, from, to);
		hanoi(n-1, by, from, to);
    }
}
