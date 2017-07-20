/*=========================================================

       8-2-1�` �`�Ƿj�M�k

          Sqn_Srch()            �`�Ƿj�M�禡
          a[ARR_NUM]            ���j�M�����
          ARR_NUM               ���j�M����Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include    <stdio.h>
#include	<stdlib.h>

#define ARR_NUM 10
int Sequential_Search(int [],int ,int );
void PrintArray(int [],int);

int main(int argc, char *argv[])
{
	int a[ARR_NUM]={39,81,6,78,69,41,52,33,55,77};
	int data,locate;

	printf("�}�C���e:");
	PrintArray(a,ARR_NUM);
	printf("\n�п�J���j�M����Ƥ��e => ");
	scanf("%d",&data);

	if((locate=Sequential_Search(a,ARR_NUM,data)) == -1)
		printf("�u�ʷj�M�k�䤣����!!!");
	else
		printf("�u�ʷj�M�k����� %d ���� %d �Ӧ�m(��0��_)",data,locate);
	printf("\n");
	system("PAUSE");
    return 0;
}

/*�ba[0..n-1]�}�C�M�����key������,�öǦ^��m*/
int Sequential_Search(int a[],int n,int key)
{
	int i;
	for(i=0 ; i < n; i++)
        if(a[i] == key)
			return(i);      /*���\�Ǧ^��m*/

   return(-1);          /*���ѶǦ^*/
}

void PrintArray(int a[],int n)
{
	int i;
	for (i=0; i<n; i++)
		printf("%d ",a[i]);
}
