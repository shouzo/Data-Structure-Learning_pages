/*=========================================================

      4-3�` ���쵲��C��@���|

	  Push()	���J���|
	  Pop() 	�۰��|�u�X���

  =========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct tagNode
	{
	   int data;			/*������*/
	   struct tagNode *next;
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
		printf("\n���|���e�ѤW��U : \n");
		PrintStack(&TopOfS);
		printf("\n(1)�ޢ��ָ��\n(2)�ޢݢ޸��\n(0)����=>");
		scanf("%d",&choose);

		switch(choose)
		{
		case 0:
			LoopFlag=0;			/*�����{��*/
			break;
		case 1:
			printf("�п�J���ޢ��֤����=>");
			scanf("\n%d",&data);
			if(Push(&TopOfS,data) == 0)
				printf("�O����t�m�����\,�ޢ��֥���");
			break;
		case 2:
			if(Pop(&TopOfS,&data) == 0)
				printf("���|�w��,�ޢݢޥ���");
			else
				printf("Pop �X : %d",data);
			break;
		default:
			printf("�ﶵ���~");
		}
   }
   system("PAUSE");	
   return 0;
}

void PrintStack(StkNode *S)
{
    StkNode  *p;
    for (p=S->next; p!= NULL; p=p->next)
	    printf("%d\t",p->data);
}

int Push(StkNode *S,int X)
{
    StkNode *p;
    if((p=(StkNode*)malloc(sizeof(StkNode)))==NULL)
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
    free(p);
    return(1);
}
