/*=========================================================

       7-6�` ���t�k

          Distribute()          ���t�k�禡
          get_key()             ���o�S�w��ƭ�(�p�Ӧ�,�Q��)
          a[ARR_NUM]            ���ƧǤ����
		  b[ARR_NUM]			�Ȧs�}�C
          ARR_NUM               ���ƧǤ���Ƽƥ�(�}�C�j�p)

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

   cout << "���t�k�Ƨǫe( before sorting ):" << endl;
   for(i=0;i < ARR_NUM;i++)
        cout << " " << a[i];
   Distribute( a, b,ARR_NUM,DIGIT_NUM);

   cout << endl << "���t�k�Ƨǫ�( after sorting ):" << endl;
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
   for (i=0; i < n; i++)     /*�p��U��ȥX�{����*/
       	Count[ a[i] ]++;
   for (j=1; j < m; j++)
       	Count[j] = Count[j] + Count[j-1];
   for (i=n-1; i >= 0; i--)   /*���t*/
   {
       	b[Count[ a[i] ]-1] = a[i];
       	Count[ a[i] ]--;
   }

   for (i=0; i < n; i++)       /*�����^a[]*/
        a[i] = b[i];
}
