/*=============================================
	1-D Array
	PrintArray(), ArrayCopy()
===============================================*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define	N	8

void ArrayCopy( int [], int [], int );
void PrintArray( int [], int);
 
int main(int argc, char *argv[])
{
	int list[N] = {5,25,11,26,39,18,120,50}, target_list[N];
	
	/* Test Array Copy */
	cout << "���� Array Copy";
    system("PAUSE");
    
	cout << "\n === Testing Array Copy ===";
	cout << "\n The contents of list ";
	PrintArray(list,N);
	ArrayCopy(target_list,list, N);
	cout << "\n target_list After Copied from list";
	PrintArray(target_list,N);
	system("PAUSE");
    return EXIT_SUCCESS;
}


/* �Nlist2�}�C�ƻs��list1�}�C, ��Ӱ}�C����n�Ӥ���  */
void ArrayCopy( int list1[], int list2[], int n)
{
	int  counter  ;
	for (counter = 0 ; counter < n ; counter++)
		list1[counter] = list2[counter] ;
}
/* �L�X�Nlist�}�C���e, list�}�C��n�Ӥ���  */
void PrintArray( int list[], int n)
{
	int  counter  ;
	for (counter = 0 ; counter < n ; counter++)
		cout << "\n list[" << counter << "]= " << list[counter] ;
	cout << "\n";
}
