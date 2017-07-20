/*=========================================================

       7-2-2�` ��ܱƧǪk

          Select_Sort()         ��ܱƧǪk�禡
          a[ARR_NUM]            ���ƧǤ����
          ARR_NUM               ���ƧǤ���Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include    <stdio.h>
#include	<stdlib.h>

#define ARR_NUM 9
void Select_Sort(int [], int);

int main(int argc, char *argv[])
{
   
   int a[ARR_NUM]={37,41,19,81,41,25,56,61,49},i;

   printf("Select Sort �Ƨǫe (before sorting)\n");
   for(i=0;i < ARR_NUM;i++)
        printf(" %d",a[i]);

   Select_Sort(a,ARR_NUM);

   printf("\nSelect Sort �Ƨǫ� ( after sorting )\n");
   for(i=0;i < ARR_NUM;i++)
        printf(" %d",a[i]);
   printf("\n");
   system("PAUSE");
   return EXIT_SUCCESS;
}
void Select_Sort(int a[],int n)
{
   int i,j,max,temp;

   for (i = n-1 ; i > 0 ; i--)
   {	
        max = i;
        for ( j=i-1 ; j >= 0 ; j--)
		    if (a[j] > a[max])
               max = j;
        temp = a[max];	
        a[max] = a[i];
        a[i] = temp;
   }

}
