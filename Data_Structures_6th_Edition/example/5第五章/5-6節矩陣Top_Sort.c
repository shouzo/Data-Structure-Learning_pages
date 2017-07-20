/*=========================================================

      5-6節 拓樸排序: 使用鄰接矩陣

	  topolody_sort()	拓樸排序函式
	  choose_next()		找到Selected為0且入分支度為0的頂點
	  M[V][V]			圖形的鄰接矩陣
	  Indegree[V]		各頂點的入分支度,初設為0
	  Selected[V]		標名各頂點是否已被輸出,初設為0

  =========================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define V	7

int M[V][V]={ {0,1,1,1,0,0,0},
		      {0,0,0,0,0,1,0},
		      {0,0,0,0,1,0,0},
		      {0,0,0,0,1,0,0},
		      {0,0,0,0,0,1,1},
		      {0,0,0,0,0,0,1},
		      {0,0,0,0,0,0,0}};
		      

int Indegree[V];
char Selected[V];

void Topolody_Sort(void);
int choose_next(void);

int main(int argc, char *argv[])
{
    Topolody_Sort();
    system("PAUSE");	
    return 0;
}

void Topolody_Sort(void)
{
    int i,j;
    int Vx;
    for (i=0;i < V;i++)
		Indegree[i]=Selected[i]=0;
    for(i=0;i < V;i++)
		for(j=0;j < V;j++)
			if(M[i][j] == 1)
				Indegree[j]++;

    for(i=0;i < V;i++)
    {
		Vx=choose_next();
		printf(" V%d ",Vx);
		for(j=0;j < V;j++)
			if (M[Vx][j] == 1)
			{
				M[Vx][j]=0;
				Indegree[j]--;
			}
	}
	printf("\n");
}

int choose_next(void)
{
    int i;
    for(i=0; i < V; i++)
		if (!Selected[i] && !Indegree[i])
		{
			Selected[i]=1;
			return(i);
		}
	return (-1);
}
