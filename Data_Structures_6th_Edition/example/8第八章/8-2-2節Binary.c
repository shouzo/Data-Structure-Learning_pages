/*=========================================================

       8-2-2�` �G���j�M�k

          bnry_Srch()           �G���j�M�禡
          a[ARR_NUM]            ���j�M�����
          ARR_NUM               ���j�M����Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include    <stdio.h>
#include	<stdlib.h>

#define ARR_NUM 10
int Binary_Search(int [],int ,int);
void PrintArray(int [],int);

int main(int argc, char *argv[])
{
	int a[ARR_NUM]={6,33,39,41,52,55,69,77,78,81};
	int data,locate;

	printf("�}�C���e:");
	PrintArray(a,ARR_NUM);
	printf("\n�п�J���j�M����Ƥ��e => ");
	scanf("%d",&data);

	if((locate=Binary_Search(a,ARR_NUM,data)) == -1)
		printf("�G���j�M�k�䤣����!!!");
	else
		printf("�G���j�M�k����� %d ���� %d �Ӧ�m(��0��_)",data,locate);
	printf("\n");
	system("PAUSE");
    return 0;
}

/*�ba[0..n-1]�}�C�M�����key������,�öǦ^��m ,�ϥ�binary Search*/
int Binary_Search(int a[],int n,int key)
{
	int l=0,r=n-1,m;

    while(l <= r)
    {
        m=(int)(l+r)/2;
        if(key == a[m])
			return(m);      /*���,�Ǧ^��m*/
        if(key > a[m])          /*�k�b��,���ܥ���*/
			l=m+1;
        else                    /*���b��,���ܥk��*/
			r=m-1;
    }

    return(-1);         /*���ѶǦ^*/
}

void PrintArray(int a[],int n)
{
	int i;
    for (i=0; i<n ; i++)
		printf("%d ",a[i]);
}
