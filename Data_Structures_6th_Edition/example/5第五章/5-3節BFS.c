/*=========================================================

      5-3�` �s���u�����X(BFS)

	  BFS ()
	  visit()		�ﳻ�IVx�@���X
	  Enqueue()		�N���IVx��J��C
	  Dequeue()		�q��C���X�@�ӳ��I��Vx
	  is_empty()	���զ�C�O�_����
	  Find_Adj()	��X�PVx�۾F�B���Q���X�L���`�I

  =========================================================
*/

#include <stdio.h>
#include <stdlib.h> 

#define MAX_ITEM 50
#define V	9	/*���I�ƥ�*/

typedef struct tagQueue
	{
		int item[MAX_ITEM];
		int front;
		int rear;
	}QUEUE;
QUEUE q;

int Col;
int visited[V];
int a[V][V]={	{0,1,1,1,0,0,0,0,0},
				{1,0,0,0,0,0,0,0,0},
				{1,0,0,0,0,0,1,1,0},
				{1,0,0,0,1,1,0,0,0},
				{0,0,0,1,0,0,0,0,0},
				{0,0,0,1,0,0,1,0,1},
				{0,0,1,0,0,1,0,1,0},
				{0,0,1,0,0,0,1,0,0},
				{0,0,0,0,0,1,0,0,0}};

void BFS(int);
void visit(int);
int Enqueue(int);
int Dequeue(int *);
int is_empty(void);
char Find_Adj(int,char);

int main(int argc, char *argv[])
{
    int V0;
    printf("�п�JBFS�_�I: ");
    scanf("%d",&V0);
    BFS(V0);
    system("PAUSE");	
    return 0;
}

void BFS (int V0)
{
    int Vx,Vy;
    visit(V0);
    Enqueue(V0);
    while(!is_empty())
    {
		Dequeue(&Vx);
		Vy=Find_Adj(Vx,1);
		while(Vy!=-1)
		{
			visit(Vy);
			Enqueue(Vy);
			Vy=Find_Adj(Vx,0);
		}
    }
}

void visit(int Vx)
{
    visited[Vx]=1;
    printf("V%2d\n",Vx);
}

int Enqueue(int Vx)
{
    if ((q.rear+1)%MAX_ITEM==q.front)
	   return(0);
    q.rear=(q.rear+1)%MAX_ITEM;
    q.item[q.rear]=Vx;
    return(1);
}

int Dequeue(int *Vx)
{
    if(is_empty())
	   return(0);
    q.front=((q.front+1)%MAX_ITEM);
    *Vx=q.item[q.front];
    return(1);
}

int is_empty(void)
{
    if(q.front == q.rear)
	   return (1);
    else
	   return (0);
}

char Find_Adj(int Vx,char first)
{
    if (first)
       Col=0;
    else
       Col++;
    while(Col < V)
    {
        if (a[Vx][Col]==0 || visited[Col])
		    Col++;
	    else
		    return (Col);
    }
    return (-1);
}
