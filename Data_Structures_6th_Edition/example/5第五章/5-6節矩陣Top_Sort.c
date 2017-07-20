/*=========================================================

      5-6�` �ݾ�Ƨ�: �ϥξF���x�}

	  topolody_sort()	�ݾ�ƧǨ禡
	  choose_next()		���Selected��0�B�J����׬�0�����I
	  M[V][V]			�ϧΪ��F���x�}
	  Indegree[V]		�U���I���J�����,��]��0
	  Selected[V]		�ЦW�U���I�O�_�w�Q��X,��]��0

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
