/*=========================================================

       7-4�` �X�ֱƧǪk

          Merge_Sort()          �X�ֱƧǪk�禡
          a[ARR_NUM]            ���ƧǤ����
          b[ARR_NUM]            �ƧǮɼȦs��ƥ�
          ARR_NUM               ���ƧǤ���Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define ARR_NUM 9

void Merge_Sort(int [],int,int);
int b[ARR_NUM];

int main(int argc, char *argv[])
{
   
   int a[ARR_NUM]={37,41,19,81,41,25,56,61,49},i;

   cout << endl << "Merge Sort �Ƨǫe ( before sorting ):" << endl ;
   for(i=0;i < ARR_NUM;i++)
        cout << " " << a[i];
   Merge_Sort(a,0,ARR_NUM-1);

   cout << endl << "Merge Sort �Ƨǫ� ( after sorting ):" << endl ;
   for(i=0;i < ARR_NUM;i++)
        cout << " " << a[i];
   cout << endl  ;
   system("PAUSE");
   return EXIT_SUCCESS;
}
void Merge_Sort(int a[],int l,int r)
{
	int i,j,k,m;
	
	if(l < r)
	{
        m=(l+r)/2;
        Merge_Sort(a,l,m);
        Merge_Sort(a,m+1,r);

        for(i=l;i <= m;i++)
			b[i]=a[i];
        for(j=m+1;j <= r;j++)
            b[r+(m-j+1)]=a[j];
        for(i=l,j=r,k=l;k <= r;k++)
            a[k]=(b[i] <= b[j]) ? b[i++]:b[j--];
	}
}
