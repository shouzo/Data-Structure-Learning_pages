/*=========================================================

       8-2-4 �O��j�M�k

          Fib_Search()          �O��j�M�禡
          a[ARR_NUM]            ���j�M�����
          ARR_NUM               ���j�M����Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include    <stdio.h>
#include	<stdlib.h>

#define MAX_NUM 12
#define Fib_NUM 20
int Fib_Search(int [],int ,int ,int);
void PrintArray(int [],int);
int F[Fib_NUM];
void Init_Fib();
int Find_Point(int);

int main(int argc, char *argv[])
{
	int a[MAX_NUM]={6,33,39,41,52,55,69,77,78,81};
	int n = 10;
	int data,locate,k;

	Init_Fib();
	k = Find_Point(n);
	
	PrintArray(a,n);
	while (1)
	{
		printf("\n�п�J���j�M����Ƥ��e (0 to stop)=> ");
		scanf("%d",&data);
		if ( data == 0)
			break;
		if((locate=Fib_Search(a,n,data,k)) == -1)
			printf("�O��j�M�k�䤣����\n!!!");
		else
			printf("�O��j�M�k����� %d ���� %d �Ӧ�m(��0��_)\n",data,locate);
	}
		
	system("PAUSE");
    return 0;
}
	
void Init_Fib()
{
	int i;
	F[0] = 0;
	F[1] = 1;
	for ( i=2; i<=Fib_NUM ; i++)
		F[i] = F[i-1] + F[i-2];
		
}

int Find_Point(int n)
{
	int k;
	for (k=0; k<Fib_NUM; k++)
		if ( (n > F[k]-1) && ( n <= F[k+1]-1))
			break;
	return k+1;
}

/*�ba[0..n-1]�}�C�M�����key������,�öǦ^��m ,�ϥ�Fibonacci Search*/
int  Fib_Search(int a[], int n, int key, int k)	//���]�w��F[k-1]-1 < n <= F[k]-1
{	int l = 0, r = n-1, m, i;

	for ( i=n; i< F[k]-1; i++)  //��J dummy key
		a[i] = a[n-1];

	while (l <= r)
	{	m = l + F[k-1] - 1 ;		//�S�����k�ΰ��k
		if (key == a[m])
		{
			if ( m < n )			//not dummy
				return (m);			//���,�Ǧ^��m
			else
				return (n-1);	
		}
		if (key < a[m])			//���b��,���ܥk��
		{	r = m-1;
			k = k - 1 ;	
		}
		else					//�k�b��,���ܥ���
		{	l = m+1;
			k = k - 2 ;
		}
	}
	return(-1);				//���ѶǦ^-1
}


void  PrintArray(int a[], int n)
{
    int i;
	for (i=0; i<n; i++)
		printf("%d ",a[i]);
}
