/*=========================================================

       7-3�` Shell�ƧǪk

          Shell_sort()          Shell�ƧǪk�禡
          a[ARR_NUM]            ���ƧǤ����
          ARR_NUM               ���ƧǤ���Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define ARR_NUM 9
void Shell_Sort(int [], int);

int main(int argc, char *argv[])
{
   
   int a[ARR_NUM]={37,41,19,81,41,25,56,61,49},i;

   cout << "Shell Sort �Ƨǫe(before sorting ):" << endl;
   for(i=0;i < ARR_NUM;i++)
        cout << " " << a[i];
   Shell_Sort(a,ARR_NUM);

   cout << endl << "Shell Sort �Ƨǫ�( after sorting ):" << endl;
   for(i=0;i < ARR_NUM;i++)
        cout << " " << a[i];
   cout << endl;
   system("PAUSE");
   return EXIT_SUCCESS;
}
void Shell_Sort(int a[],int n)
{
   int i,j,h,up;

   for(h=1; h <= n/9; h=3*h+1);

   for(;h > 0; h=h/3)
        for(i=h;i < n;i++)
        {
			up=a[i];
            j=i;
            while(j>=h && a[j-h]>up)
            {
				a[j]=a[j-h];
				j=j-h;
            }
            a[j]=up;
        }
}
