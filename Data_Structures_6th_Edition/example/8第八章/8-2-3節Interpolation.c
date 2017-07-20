/*=========================================================

       8-2-3 �����j�M�k

          Inter_Search()          �����j�M�禡
          a[ARR_NUM]            ���j�M�����
          ARR_NUM               ���j�M����Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include    <stdio.h>
#include	<stdlib.h>

#define ARR_NUM 10
int Inter_Search(int [],int ,int );
void PrintArray(int [],int);

int main(int argc, char *argv[])
{
	int a[ARR_NUM]={6,33,39,41,52,55,69,77,78,81};
	int data,locate;

	printf("�}�C���e:");
	PrintArray(a,ARR_NUM);
	printf("\n�п�J���j�M����Ƥ��e => ");
	scanf("%d",&data);

	if((locate=Inter_Search(a,ARR_NUM,data)) == -1)
		printf("�����j�M�k �䤣����!!!");
	else
        printf("�����j�M�k ����� %d ���� %d �Ӧ�m(��0��_)",data,locate);
	printf("\n");
	system("PAUSE");
    return 0;
}

/*�ba[0..n-1]�}�C�M�����key������,�öǦ^��m ,�ϥ�binary Search*/
int Inter_Search(int a[],int n,int key)
{
	int l=0,r=n-1,m;
    float x;

    while(l <= r)
    {
        if(a[r]-a[l] != 0)
			x=(float)(key-a[l])/(a[r]-a[l]);
        else
			x=1/2;
        m=l+((int)x*(r-1));
        if(key == a[m])
			return(m);      /*���,�Ǧ^��m*/
        if(key > a[m])          /*�k�b��,���ܥ���*/
			l=m+1;
        else                    /*���b��,���ܥk��*/
			r=m-1;
    }

    return(-1);         /*���ѶǦ^*/
}

void  PrintArray(int a[], int n)
{
    int i;
	for (i=0; i<n; i++)
		printf("%d ",a[i]);
}
