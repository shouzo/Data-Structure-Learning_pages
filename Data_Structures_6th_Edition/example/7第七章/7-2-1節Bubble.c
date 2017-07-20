/*=========================================================

       7-2-1�` ��w�ƧǪk

          Bubble_Sort()         ��w�ƧǪk�禡
          a[ARR_NUM]            ���ƧǤ����
          ARR_NUM               ���ƧǤ���Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include    <stdio.h>
#include	<stdlib.h>

#define ARR_NUM 9
void Bubble_Sort(int [],int);
int main(int argc, char *argv[])
{
   
	int a[ARR_NUM]={37,41,19,81,41,25,56,61,49},i;

	printf("Bubble Sort �Ƨǫe ( before sorting ):\n");
	for(i=0;i < ARR_NUM;i++)
		printf(" %d",a[i]);
	Bubble_Sort(a,ARR_NUM);

	printf("\nBubble Sort �Ƨǫ� ( after sorting ):\n");
	for(i=0;i < ARR_NUM;i++)
		printf(" %d",a[i]);
	printf("\n");
	system("PAUSE");
    return EXIT_SUCCESS;
}
void Bubble_Sort(int a[],int n)
{
	int i,j,temp;

	for(i=n-1; i > 0; i--)
		for(j=1; j <= i; j++)
			if(a[j-1] > a[j])
            {
				temp=a[j-1];
				a[j-1]=a[j];
                a[j]=temp;
            }
}
