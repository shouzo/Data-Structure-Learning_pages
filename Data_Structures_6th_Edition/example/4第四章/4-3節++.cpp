/*=========================================================

       4-3�` ���쵲��C��@���|

	  Push()	���J���|
	  Pop() 	�۰��|�u�X���

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;
typedef struct tagnode
	{
	   int data;					//������
	   struct tagnode *next;		//�쵲���
	}StkNode;
StkNode TopOfS;
int Push(StkNode *,int );
int Pop(StkNode *,int *);
void PrintStack(StkNode *);

int main(int argc, char *argv[])
{
   int choose,data,LoopFlag=1;

   while(LoopFlag)
   {
		cout << "\n���|���e�ѤW��U : \n";
		PrintStack(&TopOfS);
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
			if(Push(&TopOfS,data) == 0)
				cout << "�O����t�m�����\,�ޢ��֥���";
			break;
		case 2:
			if(Pop(&TopOfS,&data) == 0)
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

void PrintStack(StkNode *S)
{
    StkNode  *p;
    for (p=S->next; p!= NULL; p=p->next)
		cout << "  " << p->data;
}

int Push(StkNode *S,int X)
{
    StkNode *p;
    if((p=new StkNode)==NULL)
	return(0);
    p->data=X;
    p->next=S->next;
    S->next=p;
    return(1);
}
int Pop(StkNode *S,int *X)
{
    StkNode *p=S->next;
    if(p == NULL)
	return(0);
    *X=p->data;
    S->next=p->next;
    delete p;
    return(1);
}
