/*=========================================================

     5-3�` �`���u�����X(DFS): �λ��j�禡

	  DFS ()
	  visit()		�ﳻ�IVx�@���X
	  Find_Adj()	��X�PVx�۾F�B���Q���X�L���`�I

  =========================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define V	9	/*���I�ƥ�*/

void DFS(int);
void visit(int);
char Find_Adj(int, char);

int visited[V],Col;
int a[V][V]={	{0,1,1,0,0,0,0,0,0},
				{1,0,0,0,0,0,0,0,0},
				{1,0,0,0,0,0,1,1,0},
				{0,0,0,0,1,1,0,0,0},
				{0,0,0,1,0,0,0,0,0},
				{0,0,0,1,0,0,1,0,1},
				{0,0,1,0,0,1,0,1,0},
				{0,0,1,0,0,0,1,0,0},
				{0,0,0,0,0,1,0,0,0}};

int main(int argc, char *argv[])
{
    int V0;

    printf("�п�JDFS�_�I: ");
    scanf("%d",&V0);
    DFS(V0);
    system("PAUSE");	
    return 0;
}

void DFS(int V0)
{
    int Vx,temp;
    visit(V0);
    Vx=Find_Adj(V0,1);
    while(Vx != -1)
    {
		temp=Col;	/*�NCol���s�_��,�H�K���j�I�s�ɳQ���*/
		DFS(Vx);
		Col=temp;
		Vx=Find_Adj(V0,0);
    }
}

void visit(int Vx)
{
    visited[Vx]=1;
    printf("V%2d\n",Vx);
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
    return(-1);
}
