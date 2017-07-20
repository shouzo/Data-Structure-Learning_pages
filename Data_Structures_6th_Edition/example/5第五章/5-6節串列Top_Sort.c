/*=========================================================

      5-6�` �ݾ�Ƨ�:�ϥξF����C

	  topolody_sort()  �ݾ�ƧǨ禡
	  M_to_List()	   �N�F���x�}�@���F����C

  =========================================================
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define V	7
typedef struct node
	{
		int vertex;
		struct node *next;
	}ANODE;
ANODE AdjList[V];

int M[V][V]={	{0,1,1,1,0,0,0},
				{0,0,0,0,0,1,0},
				{0,0,0,0,1,0,0},
				{0,0,0,0,1,0,0},
				{0,0,0,0,0,1,1},
				{0,0,0,0,0,0,1},
				{0,0,0,0,0,0,0}};

void M_to_List(void);
void Topology_Sort(void);
void PrintList(int);

int main(int argc, char *argv[])
{
    M_to_List();
    Topology_Sort();
    system("PAUSE");	
    return 0;
}

void Topology_Sort(void)
{
    int i,n,top=-1,k;
    ANODE *p;
    for(i=0;i < V;i++)
		if(AdjList[i].vertex == 0)
		{
			AdjList[i].vertex=top;
			top=i;
		}
    for(i=0;i < V;i++)
    {
		if(top == -1)
		{
			printf("NetWork has a cycle\n");
			break;
		}
		n=top;
		top=AdjList[top].vertex;
		printf(" V%d ",n);
		p=AdjList[n].next;
		while(p != NULL)
		{
			k=p->vertex;
			(AdjList[k].vertex)--;
			if(AdjList[k].vertex == 0)
			{
				AdjList[k].vertex=top;
				top=k;
			}
			p=p->next;
		}
    }
}

void M_to_List(void)
{
    int i,j;
    ANODE *New_Node,*p;

	for(i=0;i < V;i++)
    {
		AdjList[i].next=NULL;
		AdjList[i].vertex=0;
	}
    for(i=0;i < V;i++)
    {
		p=&AdjList[i];
		for(j=0;j < V;j++)
			if(M[i][j] == 1)
			{
				AdjList[j].vertex++;
				New_Node = (ANODE *)malloc(sizeof(ANODE));
				New_Node->vertex=j;
				New_Node->next=NULL;
				p->next=New_Node;
				p=p->next;
			}
		/*PrintList(i);*/
    }
}

void PrintList(int Vx)
{
	ANODE *p=AdjList[Vx].next;
	printf("The List of V%d is :\n",Vx);	
	while ( p )
	{
			printf(" V%d ",p->vertex);
			p=p->next;
	}
	printf("\n");
		
}
