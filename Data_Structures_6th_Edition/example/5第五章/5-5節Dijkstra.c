/*=========================================================

      5-5�` �q�Y�@�I���l�U�I���̵u���|

	  Dijkstra()	Dijkstra�t��k
	  find_min()	��XDecided[]=0�BDist�̤p��

	  Cost[V][V]	�ϧΪ��[�v�F���x�}
	  Dist[V]	�q�_�I��U�I���̵u�Z��
	  Prior[V]	�U�I�̵u���|�����e�@�ӳ��I
	  Decided[V]	�̵u���w�O�_�w�M�w

  =========================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define V	7

int Cost[V][V]={{0,1,4,5,15000,15000,15000},
		{1,0,15000,2,15000,15000,15000},
		{4,15000,0,4,15000,3,15000},
		{5,2,4,0,5,2,15000},
		{15000,15000,15000,5,0,15000,6},
		{15000,15000,3,2,15000,0,4},
		{15000,15000,15000,15000,6,4,0}};

int Dist[V],Prior[V],Decided[V];

void Dijstra(int);
void find_min(int *);
void PrintPath(int, int);

int main(int argc, char *argv[])
{
    int i,V0;
    
    printf("�п�J�_�I: ");
    scanf("%d",&V0);
    Dijstra(V0);

    for(i=0; i < V; i++)
    {
		if(i == V0)
			continue;
		printf("\nV%2d --> V%2d  Cost == %d\n",V0,i,Dist[i]);
		PrintPath(V0,i);
    }
    system("PAUSE");	
    return 0;
}

void Dijstra(int V0)
{
    int Vx;
    int i,w;
    for(i=0;i<V;i++)
    {
		Dist[i]=Cost[V0][i];
		Prior[i]=0;
		Decided[i]=0;
    }
    Decided[0]=1;

    for(i=1;i<V;i++)
    {
	  find_min(&Vx);
	  Decided[Vx]=1;
	  for(w=0;w<V;w++)
	  {
		if(!Decided[w] && (Dist[w] > (Dist[Vx]+Cost[Vx][w])))
		{
			Dist[w]=Dist[Vx]+Cost[Vx][w];
			Prior[w]=Vx;
		}
	  }
    }
}

void find_min(int *Vx)
{
    int i;
    int l=0,lowest=32767;
    for(i=0;i<V;i++)
		if (!Decided[i] && Dist[i]<lowest)
		{
			lowest=Dist[i];
			l=i;
		}
    *Vx=l;
}

void PrintPath(int V0,int Vx)
{
  int i;

  printf("V%d ���e�@���O ",Vx);
  for (i=Prior[Vx]; i!= V0 ; i=Prior[i])
       printf("V%d, V%d ���e�@���O ",i,i);
  printf("V%d\n ",V0);
}
