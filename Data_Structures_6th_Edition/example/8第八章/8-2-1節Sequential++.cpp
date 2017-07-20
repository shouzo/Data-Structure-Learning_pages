/*=========================================================

       8-2-1�` �`�Ƿj�M�k

          Sqn_Srch()            �`�Ƿj�M�禡
          a[ARR_NUM]            ���j�M�����
          ARR_NUM               ���j�M����Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define ARR_NUM 10
int Sequential_Search(int [],int ,int );
void PrintArray(int [],int);

int main(int argc, char *argv[])
{
	int a[ARR_NUM]={39,81,6,78,69,41,52,33,55,77};
	int data,locate;

	cout << "�}�C���e:";
	PrintArray(a,ARR_NUM);
	cout << endl << "�п�J���j�M����Ƥ��e => ";
	cin >> data;

	if((locate=Sequential_Search(a,ARR_NUM,data)) == -1)
		cout << "�`�Ƿj�M�k�䤣����!!!";
	else
		cout << "�`�Ƿj�M�k����� " << data << " ���� " << locate << " �Ӧ�m (��0��_)";
	cout << endl;
	system("PAUSE");
    return EXIT_SUCCESS;
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
		cout << " " << a[i];
}
