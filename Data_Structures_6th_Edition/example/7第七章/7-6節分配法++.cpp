/*=========================================================

       7-6節 分配法

          Distribute()          分配法函式
          get_key()             取得特定位數值(如個位,十位)
          a[ARR_NUM]            欲排序之資料
		  b[ARR_NUM]			暫存陣列
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define ARR_NUM		12
#define	DIGIT_NUM	10

void Distribute(int [],int [],int ,int );

int main(int argc, char *argv[])
{
   
   int a[ARR_NUM]={9,2,3,5,3,5,6,2,3,5,7,0},b[ARR_NUM],i;

   cout << "分配法排序前( before sorting ):" << endl;
   for(i=0;i < ARR_NUM;i++)
        cout << " " << a[i];
   Distribute( a, b,ARR_NUM,DIGIT_NUM);

   cout << endl << "分配法排序後( after sorting ):" << endl;
   for(i=0;i < ARR_NUM;i++)
        cout << " " << a[i];
   cout << endl;
   system("PAUSE");
   return EXIT_SUCCESS;
}


void Distribute(int a[],int b[],int n,int m)
{
   int i,j;
   int Count[m];

   for (j=0; j < m; j++)
       	Count[j]=0;
   for (i=0; i < n; i++)     /*計算各鍵值出現次數*/
       	Count[ a[i] ]++;
   for (j=1; j < m; j++)
       	Count[j] = Count[j] + Count[j-1];
   for (i=n-1; i >= 0; i--)   /*分配*/
   {
       	b[Count[ a[i] ]-1] = a[i];
       	Count[ a[i] ]--;
   }

   for (i=0; i < n; i++)       /*拷貝回a[]*/
        a[i] = b[i];
}
