/*=========================================================
	 4-2�`
       
	  Push()	���J���|
	  IsFull()	���լO�_�w��
	  Pop() 	�۰��|�u�X���
	  IsEmpty()	���լO�_�w��

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX_ITEM	9

typedef struct tagSTACK
	{
	   int item[MAX_ITEM];        /*������*/
	   int	top;
	}STACK;

int Push(STACK *,int );
int IsFull(STACK *);
int Pop(STACK *,int *);
int IsEmpty(STACK *);
void PrintStack(STACK *);

int main(int argc, char *argv[])
{
   STACK S;
   int choose,LoopFlag=1;
   int data;

   S.top=-1;
   while(LoopFlag)
   {
		cout << "\n ���|���e�ѤW��U : \n";
		PrintStack(&S);
		cout << "\n(1)�ޢ��ָ��\n(2)�ޢݢ޸��\n(0)���� => ";
		cin >> choose;

		switch(choose)
		{
		case 0:
			LoopFlag=0;			/*�����{��*/
			break;
		case 1:
			cout << "�п�J���ޢ��֤���� => ";
			cin >> data;
			if(Push(&S,data) == 0)
				cout << "���|�w��,�ޢ��֥���";
			break;
		case 2:
			if(Pop(&S,&data) == 0)
				cout << "���|�w��,�ޢݢޥ���";
			else
			cout << "Pop �X : " << data;
			break;
		default:
			cout << "�ﶵ���~";
		}
   }
    system("PAUSE");
    return EXIT_SUCCESS;
}

void PrintStack( STACK *s)
{
   int i;
   if ( IsEmpty(s) )
      return ;
   for (i=s->top;i >= 0;i--)
      cout << "  " << s->item[i];
   cout << "\n";
}

int Push(STACK *S,int X)
{
    if(IsFull(S))
	   return(0);
    S->top=S->top+1;
    S->item[S->top]=X;
	return(1);
}

int IsFull(STACK *S)
{
    if (S->top == (MAX_ITEM-1))
	   return(1);
    else
	return(0);
}

int Pop(STACK *S,int *X)
{
    if(IsEmpty(S))
	   return (0);
    *X=S->item[S->top];
    S->top--;
	return(1);
}

int IsEmpty(STACK *S)
{
    if(S->top == -1)
	   return(1);
    else
	   return(0);
}
