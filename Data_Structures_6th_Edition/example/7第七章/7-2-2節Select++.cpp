/*=========================================================

       7-2-2�` ��ܱƧǪk

          Select_Sort()         ��ܱƧǪk�禡
          a[ARR_NUM]            ���ƧǤ����
          ARR_NUM               ���ƧǤ���Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define ARR_NUM 9
void Select_Sort(int [], int);

int main(int argc, char *argv[])
{
   
   int a[ARR_NUM]={37,41,19,81,41,25,56,61,49},i;

   cout << "Select Sort �Ƨǫe (before sorting)" << endl;
   for(i=0;i < ARR_NUM;i++)
        cout << " " << a[i];

   Select_Sort(a,ARR_NUM);

   cout << endl << "Select Sort �Ƨǫ� ( after sorting)" << endl;
   for(i=0;i < ARR_NUM;i++)
        cout << " " << a[i];
   cout << endl;
   system("PAUSE");
   return EXIT_SUCCESS;
}
void Select_Sort(int a[],int n)
{
   int i,j,min,temp;

   for(i=0; i < n-1; i++)
   {
        min=i;
        for(j=i+1; j < n ;j++)
			if(a[j] < a[min])
				min=j;
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
   }
}
