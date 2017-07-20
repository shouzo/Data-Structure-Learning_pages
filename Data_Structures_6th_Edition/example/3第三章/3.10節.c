/*=========================================================

    ��3-10�`: �쵲��C������ -- �h�������[�k
		
	  InsertAfter() ���J�`�I
	  DeleteNode()	�R���`�I
	  Read_data()	�۫��w�ɮ�Ū�J���
	  ViewP()	�L�X�h����
	  FreeAllNode() ����Ҧ��`�I���O����Ŷ�

  =========================================================
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tagPListNode
	{
	   float coef;			/*�Y��*/
	   int	 expo;			/*����*/
	   struct tagPListNode *next;
	}PListNode;

PListNode *AddTail(PListNode *,float,int);
PListNode	*PolyAdd(PListNode *,PListNode *);
void FreeAllNode(PListNode *);
void ViewP(PListNode *);
void Read_data(FILE *,PListNode *);

int main(int argc, char *argv[])
{
   FILE *fin1,*fin2;
   PListNode	*Pa,*Pb,*Pc;
 
   if((fin1=fopen("PolyA.in","r"))==NULL || (fin2=fopen("PolyB.in","r"))==NULL)
   {
	   printf("�}�ɥ���,�����{��");
	   return 1;
   }

   Pa=(PListNode *)malloc(sizeof(PListNode));
   Pb=(PListNode *)malloc(sizeof(PListNode));

   Read_data(fin1,Pa);
   Read_data(fin2,Pb);

   Pc=PolyAdd(Pa,Pb);

   ViewP(Pa);
   printf("+\n");
   ViewP(Pb);
   printf("=\n");
   ViewP(Pc);

   FreeAllNode(Pa);
   FreeAllNode(Pb);
   FreeAllNode(Pc);
   system("PAUSE");	
   return 0;
}

PListNode *AddTail(PListNode *tail,float co,int ex)
{
   PListNode *p;
   p=(PListNode *)malloc(sizeof(PListNode));
   p->coef=co;
   p->expo=ex;
   p->next=NULL;
   tail->next=p;
   tail=p;
  
   return(tail);
}

PListNode *PolyAdd(PListNode *pa,PListNode *pb)
{
   PListNode *c,*ctail;
   c=(PListNode *)malloc(sizeof(PListNode));
   ctail=c;

   pa=pa->next;
   pb=pb->next;
   while(pa && pb)
   {
      if(pa->expo > pb->expo)
	  {
		 ctail=AddTail(ctail,pa->coef,pa->expo);
		 pa=pa->next;
	  }
	  else if(pa->expo < pb->expo)
	  {
		 ctail=AddTail(ctail,pb->coef,pb->expo);
		 pb=pb->next;
	  }
	  else
	  {
		if((pa->coef + pb->coef) != 0)
			ctail=AddTail(ctail,pa->coef+pb->coef,pa->expo);
		pa=pa->next;
		pb=pb->next;
	  }
   }
   while(pa)
   {
	   ctail=AddTail(ctail,pa->coef,pa->expo);
	   pa=pa->next;
   }
   while(pb)
   {
	   ctail=AddTail(ctail,pb->coef,pb->expo);
	   pb=pb->next;
   }
   return (c);
}
void Read_data(FILE *f,PListNode *Tail)
{
   int expo;
   float coef;

   fscanf(f,"%f",&coef);        /*��ŪŪ�ݫY�Ƥέ���,�Y���F�ɧ�,�Y*/
   fscanf(f,"%d",&expo);        /*��Ū�J���\��~�إߦ��`�I,�_�h�|�y*/
   while(!feof(f))				/*���̫�@����Ʒ|�إߨ⦸*/
   {
	  Tail=AddTail(Tail,coef,expo);
	  fscanf(f,"%f",&coef);
	  fscanf(f,"%d",&expo);
   }
}

void ViewP(PListNode *p)
{
    p = p->next;
	for(;p->next != NULL;p=p->next)
		printf("%2.1fX%d + ",p->coef,p->expo);
	printf("%2.1fX%d\n",p->coef,p->expo);
   
}

void FreeAllNode(PListNode *head)
{
   PListNode *next_node;

   while(head->next != NULL)
   {
	  next_node=head->next;
	  free(head);
	  head=next_node;
   }
   free(head);
}
