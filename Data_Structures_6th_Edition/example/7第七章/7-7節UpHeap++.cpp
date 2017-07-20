/*=========================================================

       7-7�` Up_Heap �إ߰�n

          Construct_by_Insert() �N�}�C�վ㦨��n
          Up_Heap()				�վ��n,�H�ŦX�S��
          a[ARR_NUM]            ���ƧǤ����
          ARR_NUM               ���ƧǤ���Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define ARR_NUM 10

void Construct_by_Insert(int [], int);
void Up_Heap(int [], int);

int main(int argc, char *argv[])
{
	int a[ARR_NUM]={38,72,67,41,39,72,37,25,66,73},i;

	cout <<"Up Heap�k �إ߰�n�e ( before adjusting ):" << endl;
	for(i=0;i < ARR_NUM;i++)
		cout << " " << a[i];
	Construct_by_Insert(a,ARR_NUM);

	cout << endl << "Up Heap�k �إ߰�n�� ( after adjusting ):" << endl;
	for(i=0;i < ARR_NUM;i++)
		cout << " " << a[i];
	cout << endl;
	system("PAUSE");
    return EXIT_SUCCESS;
}


/*�Na[k]���W�վ�,�H�ŦXheap�S��*/
void Up_Heap(int a[],int k)
{
	int up;
	up = a[k];
	while(((k-1)/2 >= 0) && (a[(k-1)/2] < up))  /*�P���`�I���*/
	{
		a[k] = a[(k-1)/2];    /* ���`�I�U��*/
        k = (k-1)/2 ;
		if (k==0) break;
	}
	a[k]=up;
}

/*�δ��J���覡�إ߰�n a[0 ~ n-1]*/
void Construct_by_Insert(int a[],int n)
{
	int k;
	for( k = 1; k < n; k++)
		Up_Heap(a,k);
}
