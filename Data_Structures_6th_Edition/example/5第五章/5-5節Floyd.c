/*=========================================================

      5-5�` �C�@�ﳻ�I�����̵u���|

	  floyd()	floyd�t��k
	  search_path() �l��P�x�}

	  COST[V][V]	�ϧΪ��[�v�F���x�}

  =========================================================
*/

#include <stdio.h>
#include <stdlib.h>

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
    return 0;
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
			printf("Shortest Path from V%d to V%d cost is:%d\n",i,j,A[i][j]);
			printf("Shortest path is:\n from v%d ",i);
			row=P[i][j];
			while(row != j)
			{
				printf(" to V%d",row);
				row=P[row][j];
			}
			printf(" to V%d\n",row);
		}
}
