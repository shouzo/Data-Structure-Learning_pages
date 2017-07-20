/*=============================================
	1-D array
	PrintArray(), ArrayCopy()
===============================================*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 

#define	N	8

void ArrayCopy( int [], int [], int );
void PrintArray( int [], int);

void main(void)
{
	int list[N] = {5,25,11,26,39,18,120,50}, target_list[N];
	int value, position;

	/* Test Array Copy */
	printf("\n Press any key to test Array Copy...");
	getch();
	printf("\n The contents of list ");
	PrintArray(list,N);
	ArrayCopy(target_list,list, N);
	printf("\n target_list After Copied from list");
	PrintArray(target_list,N);
	system("PAUSE");
    return 0;
}


/* 將list2陣列複製到list1陣列, 兩個陣列都有n個元素  */
void ArrayCopy( int list1[], int list2[], int n)
{
	int  counter  ;
	for (counter = 0 ; counter < n ; counter++)
		list1[counter] = list2[counter] ;
}
/* 印出將list陣列內容, list陣列有n個元素  */
void PrintArray( int list[], int n)
{
	int  counter  ;
	for (counter = 0 ; counter < n ; counter++)
		printf("\n list[%d]= %d ",counter,list[counter]) ;
	printf("\n");
}
