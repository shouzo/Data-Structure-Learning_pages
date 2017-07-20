/*=========================================================

      5-5�` �C�@�ﳻ�I�����̵u���|

	  floyd()	floyd�t��k
	  search_path() �l��P�x�}

	  COST[V][V]	�ϧΪ��[�v�F���x�}

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define v	7

int COST[v][v]={{0,1,4,5,15000,15000,15000},
				{1,0,15000,2,15000,15000,15000},
				{4,15000,0,4,15000,3,15000},
				{5,2,4,0,5,2,15000},
				{15000,15000,15000,5,0,15000,6},
				{15000,15000,3,2,15000,0,4},
				{15000,15000,15000,15000,6,4,0}};

int A[v][v],P[v][v];

void floyd(void);
void search_path(int [][v]);

int main(int argc, char *argv[])
{
    floyd();
    search_path(P);
    system("PAUSE");
    return EXIT_SUCCESS;
}

void floyd(void)
{
    int i,j,k;
    for(i=0;i < v;i++)
		for(j=0;j < v;j++)
		{
			A[i][j]=COST[i][j];
			P[i][j]=j;
		}
    for(k=0;k < v;k++)
		for(i=0;i < v;i++)
			for(j=0;j < v;j++)
				if(A[i][j] > A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					P[i][j]=P[i][k];
				}
}

void search_path(int P[][v])
{
    int i,j,row;
    for(i=0;i < v;i++)
		for(j=0;j < v;j++)
		{
			cout << "Shortest Path from V" << i << " to V" << j << " cost is :" << A[i][j] << endl;
			cout << "Shortest Path is:" << endl << " from V" << i ;
			row=P[i][j];
			while(row != j)
			{
				cout << " to V" << row;
				row=P[row][j];
			}
			cout << " to V" << row << endl;
		}
}
