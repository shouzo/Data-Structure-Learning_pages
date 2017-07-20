/*=========================================================

       7-2-2節 選擇排序法

          Select_Sort()         選擇排序法函式
          a[ARR_NUM]            欲排序之資料
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include    <stdio.h>
#include	<stdlib.h>

#define ARR_NUM 9
void Select_Sort(int [], int);

int main(int argc, char *argv[])
{
   
   int a[ARR_NUM]={37,41,19,81,41,25,56,61,49},i;

   printf("Select Sort 排序前 (before sorting)\n");
   for(i=0;i < ARR_NUM;i++)
        printf(" %d",a[i]);

   Select_Sort(a,ARR_NUM);

   printf("\nSelect Sort 排序後 ( after sorting )\n");
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
