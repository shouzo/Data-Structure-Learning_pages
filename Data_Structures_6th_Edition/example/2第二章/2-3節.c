/*=========================================================
    �ĤG��

      2-D Array

          MAX_SIZE          �̤j�C�ƩΦ�� 
          ArrTrans()        �}�C��m
          A1[rows][cols]    �s�����m�}�C���e
          B1[cols][rows]    �s����m��}�C���e
          rows              �C��
          cols              ���
		  A2[rows][cols]    �s��ݬۥ[�}�C���e
          B2[rows][cols]	�s��ݬۥ[�}�C���e
		  C2[rows][cols]	�s��}�C�ۥ[�᤺�e
          A3[m][n]			�s��ݬۭ��}�C���e
          B3[n][t]			�s��ݬۭ��}�C���e
		  C3[m][t]			�s��}�C�ۭ��᤺�e

  =========================================================
*/

#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 100 

void ArrTrans(int [][MAX_SIZE],int [][MAX_SIZE], int, int);
void ArrAdd(int [][MAX_SIZE],int [][MAX_SIZE],int [][MAX_SIZE], int, int);
void ArrMul(int [][MAX_SIZE],int [][MAX_SIZE],int [][MAX_SIZE], int, int, int);
void PrintMatrix(int [][MAX_SIZE], int, int);
int main(int argc, char *argv[])
{
   int rows = 4, cols = 3, m = 3, n = 2, t = 4; 
   int A1[MAX_SIZE][MAX_SIZE]={  {1,2,3},
                                 {4,5,6},
                                 {7,8,9},
                                 {10,11,12}};
   int B1[MAX_SIZE][MAX_SIZE];
   int A2[MAX_SIZE][MAX_SIZE]={  {1,2,3},
                                  {4,5,6},
                                  {7,8,9},
                                  {10,11,12}};
   int B2[MAX_SIZE][MAX_SIZE]={  {0,1,2},
                                 {3,4,5},
                                 {6,7,8},
                                 {9,10,11}};
   int C2[MAX_SIZE][MAX_SIZE];
   int A3[MAX_SIZE][MAX_SIZE]={{1,2},
                               {4,5},
                               {3,6}};
   int B3[MAX_SIZE][MAX_SIZE]={{0,1,1,2},
                               {4,0,-1,3}};
   int C3[MAX_SIZE][MAX_SIZE];
   	
   /* Test Array Transposition */
   printf("\nPress any key to test Array Transpose (�����@�����x�}��m) ");
   getch();
   ArrTrans(A1,B1, rows, cols);
   printf("\n�x�}A =>\n");
   PrintMatrix(A1, rows, cols);
   printf("�x�}A ����m �x�}B=>\n");
   PrintMatrix(B1, cols, rows);

	/* Test Array Addition */
   printf("\nPress any key to test Array Addition (�����@�����x�}�ۥ[) ");
   getch();
   ArrAdd(A2,B2,C2, rows, cols);
   printf("\n�x�}A =>\n");
   PrintMatrix(A2, rows, cols);
   printf("�[�x�}B =>\n");
   PrintMatrix(B2, rows, cols);
   printf("����x�}C =>\n");
   PrintMatrix(C2, rows, cols);

   /* Test Array Multiplication */
   printf("\nPress any key to test Array Multiplication (�����@�����x�}�ۭ�) ");
   getch();
   ArrMul(A3,B3,C3, m, n, t);
   printf("\n�x�}A =>\n");
   PrintMatrix(A3, m, n);
   printf("���x�}B =>\n");
   PrintMatrix(B3, n, t);
   printf("����x�}C =>\n");
   PrintMatrix(C3, m, t);
   system("PAUSE");	
   return 0;

}

void ArrTrans(int A[][MAX_SIZE],int B[][MAX_SIZE], int rows, int cols)
{
   int i,j;

   for(i=0 ;i < rows ;i++)
        for(j=0 ;j < cols ;j++)
                B[j][i]=A[i][j];
}
void ArrAdd(int A[][MAX_SIZE],int B[][MAX_SIZE],int C[][MAX_SIZE], int rows, int cols )
{
     int i,j;
     for(i=0; i < rows ; i++)
	    for(j=0; j < cols ; j++)
		     C[i][j] = A[i][j] + B[i][j] ;
}

void ArrMul(int A[][MAX_SIZE],int B[][MAX_SIZE],int C[][MAX_SIZE], int m, int n, int t )
{
    int i, j, k ;

    for( i=0; i < m; i++)
	  for( j=0; j < t; j++)
	  {
		C[i][j] = 0 ;	
		for( k=0; k < n; k++)
		      C[i][j] = C[i][j]+ A[i][k] * B[k][j] ;
	  }
}

void PrintMatrix(int A[][MAX_SIZE], int rows, int cols)
{
   int i,j;

   for(i=0;i < rows;i++)
   {
        for(j=0;j < cols;j++)
                printf("%d\t",A[i][j]);
        printf("\n");
   }
}
