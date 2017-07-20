/*=========================================================

       8-2-3 �����j�M�k

          Inter_Search()          �����j�M�禡
          a[ARR_NUM]            ���j�M�����
          ARR_NUM               ���j�M����Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define ARR_NUM 10
int Inter_Search(int [],int ,int );
void PrintArray(int [],int);

int main(int argc, char *argv[])
{
	int a[ARR_NUM]={6,33,39,41,52,55,69,77,78,81};
	int data,locate;

	cout << "�}�C���e:";
	PrintArray(a,ARR_NUM);
	cout << endl << "�п�J���j�M����Ƥ��e => ";
	cin >> data;

	if((locate=Inter_Search(a,ARR_NUM,data)) == -1)
		cout << "�����j�M�k�䤣����!!!";
	else
        cout << "�����j�M�k����� " << data << " ���� " << locate << " �Ӧ�m ( ��0��_ )";
	cout << endl;
	system("PAUSE");
    return EXIT_SUCCESS;
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
		cout << " " << a[i];
}
