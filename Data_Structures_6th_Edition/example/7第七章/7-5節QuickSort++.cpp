/*=========================================================

       7-5�` �ֳt�ƧǪk

          Quick_Sort()          �ֳt�ƧǪk�禡
          partition()           ���ΰ}�C�禡
          a[ARR_NUM]            ���ƧǤ����
          ARR_NUM               ���ƧǤ���Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define ARR_NUM 9
void Quick_Sort(int [],int,int);
int Partition(int [],int,int);

int main(int argc, char *argv[])
{
    int a[ARR_NUM]={37,41,19,81,41,25,56,61,49},i;

	cout << "Quick Sort �Ƨǫe ( before sorting ):" << endl;
	for(i=0;i < ARR_NUM;i++)
		cout << " " << a[i];
	Quick_Sort(a,0,ARR_NUM-1);

	cout << endl << "Quick Sort �Ƨǫ� ( after sorting ):" << endl;
	for(i=0;i < ARR_NUM;i++)
		cout << " " << a[i];
	cout << endl;
	system("PAUSE");
    return EXIT_SUCCESS;
}

/*�ֳt�ƧǪk*/
void Quick_Sort(int a[],int l,int r)
{
   int partition_point;
   if(l < r)
   {
        partition_point=Partition(a,l,r);       /*����*/

        Quick_Sort(a,l,partition_point-1);      /*���B���b��*/

        Quick_Sort(a,partition_point+1,r);      /*���B�k�b��*/
   }
}

/*�� a[l]..a[r] �i�����,�Ǧ^�����I*/
int Partition(int a[],int l,int r)
{
   int i,j,temp;

   for(i=l+1,j=r;;)
   {
		while(a[i]<a[l] && i<=r)
			i++;
        while(a[j] > a[l])
            j--;

        if(i >= j)
			break;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
   }
   temp=a[l];
   a[l]=a[j];
   a[j]=temp;

   return(j);
}
