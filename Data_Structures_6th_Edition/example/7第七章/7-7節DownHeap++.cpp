/*=========================================================

       7-7�` Down_Heap �إ߰�n

          Construct_by_Adjust() �N�}�C�վ㦨��n
          Down_Heap()            �վ��n,�H�ŦX�S��
          a[ARR_NUM]            ���ƧǤ����
          ARR_NUM               ���ƧǤ���Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define ARR_NUM 10

void Construct_by_Adjust(int [], int);
void Down_Heap(int [], int,int);

int main(int argc, char *argv[])
{
	int a[ARR_NUM]={38,72,67,41,39,72,37,25,66,73},i;

	cout << "Down Heap�k �إ߰�n�e ( before Adjusting ):" << endl;
	for(i=0;i < ARR_NUM;i++)
		cout << " " << a[i];
	Construct_by_Adjust(a,ARR_NUM);

	cout << endl << "Down Heap�k �إ߰�n�� ( after Adjusting ):" << endl;
	for(i=0;i < ARR_NUM;i++)
		cout << " " << a[i];
	cout << endl;
	system("PAUSE");
    return EXIT_SUCCESS;
}


/*�νվ㪺�覡�إ߰�n a[n]*/
void Construct_by_Adjust(int a[],int n)
{
	int k;

	for(k=n/2-1;k >= 0;k--)
		Down_Heap(a,n,k);

}

/*�Na[k]���U�վ�,�H�ŦXheap�S��*/
void Down_Heap(int a[],int n,int k)
{
	int j,up;
	up=a[k];
	while(k < n/2)               /*a[k]�������l�`�I*/
	{
		j=2*k+1;                /*a[k]������la[j]*/
        if(j+1<n && a[j]<a[j+1])
			j++;
        /*�Y�k��l���j�B�s�b;a[j]��a[k]���k��l*/
        if(up >= a[j])
			break;  /*�j��j��l*/
        a[k]=a[j];              /*�j��l�W��*/
        k=j;
	}
	a[k]=up;
}
