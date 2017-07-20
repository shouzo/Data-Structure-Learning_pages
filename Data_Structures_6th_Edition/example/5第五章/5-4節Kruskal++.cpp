/*=========================================================

      5-4 �` Kruskal

	  Kruskal()	Kruskal�t��k�禡
	  init()	�}��Ū�J E  �}�C
	  SelectEdge()	��X��O�̤p�B���J�諸��
	  Cycle()	�P�_ex�[�J ST ����O�_�|�y������
	  PrintST()	�L�X�̫᪺���G
	  FindRoot()	�M��P�@���X����(�N��)
	  AddEdge()	��@��[�J ST ��

  =========================================================
*/

#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

#define 	e	7
#define 	V	5

typedef struct edge
	{
		int Vx,Vy;
		int cost;
		int selected;
	}EDGE;
EDGE E[e];

int Vertex[V];
int TotalCost ;
ifstream	fin;

int init(void);
void Kruskal(void);
int SelectEdge(void);
char Cycle(int);
void AddEdge(int);
void PrintST(int);
int  FindRoot(int);

int main(int argc, char *argv[])
{
	int FlagInit;
    FlagInit = init();
    if (FlagInit)
	 	Kruskal();
	system("PAUSE");
    return EXIT_SUCCESS;
}

int init(void)
{
  int i;

  for (i=0; i<V; i++)
       Vertex[i]=i;    // ��] 
	
  fin.open("Kruskal.in", ios::in);
  if ( !fin.good() )
  {
      cout << "�}�ɥ���, �����{��";
	  return 0;
  }
  cout << " Vx  " <<  " Vy  " <<  " cost  " << "\n";
  for (i=0;i<e;i++)
  {
	  fin >> E[i].Vx >> E[i].Vy >> E[i].cost >> E[i].selected;
	  cout << "  " << E[i].Vx << "    " <<  E[i].Vy << "    " << E[i].cost << "    " << "\n";
  }
  fin.close();
  return 1;
}

void Kruskal(void)
{

    int edge=0;
    int ex;
    while(edge < V-1)
    {
		ex=SelectEdge();
		if(!Cycle(ex))
		{
			AddEdge(ex);
			edge++;
			PrintST(ex);
		}
		else
			E[ex].selected=2;
	}
	cout << "Totol Cost is : " << TotalCost << "\n";
}

int SelectEdge(void)
{
    int ex=0,i;
    int min_cost = 32767;
	for (i=0; i<e ; i++)
		if( (E[i].selected == 0) && (E[i].cost < min_cost) )
		{
			min_cost = E[i].cost;
			ex = i;
		}
    return(ex);
}

int FindRoot( int vx)
{
   while ( Vertex[vx] != vx)
		vx=Vertex[vx];
   return ( vx );
}

char Cycle(int ex)
{
    int i,j;

    i=FindRoot(E[ex].Vx);
    j=FindRoot(E[ex].Vy);
    if ( i==j)	      // �ݩ�P�@���X
		return(1);
    return(0);
}

void AddEdge( int ex)
{
   int i,j;

   E[ex].selected = 1;
   i = FindRoot( E[ex].Vx );
   j = FindRoot( E[ex].Vy );
   Vertex[i]=j;        //�X���@���X
}

void PrintST(int i)
{
    if(E[i].selected==1)
	{
		cout << "V" << E[i].Vx << ",V" << E[i].Vy << " selected, cost=" << E[i].cost << "\n";
		TotalCost = TotalCost+E[i].cost;
	}
    
}
