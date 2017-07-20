/*=========================================================

    ��3-10�`: �쵲��C������ -- �h�������[�k
		
	  InsertAfter() ���J�`�I
	  DeleteNode()	�R���`�I
	  Read_data()	�۫��w�ɮ�Ū�J���
	  ViewP()	�L�X�h����
	  FreeAllNode() ����Ҧ��`�I���O����Ŷ�

  =========================================================
*/

#include <cstdlib>
#include <iostream>
#include <fstream> 

using namespace std;

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
void Read_data(fstream &,PListNode *);


int main(int argc, char *argv[])
{
   fstream fin1,fin2;
   PListNode	*Pa,*Pb,*Pc;
 
   fin1.open("PolyA.in",ios::in);
   fin2.open("PolyB.in",ios::in);
   if( !fin1 || !fin2)
   {
	   cout << "�}�ɥ���,�����{��";
	   return !EXIT_SUCCESS;
   }

   Pa = new PListNode;
   Pb = new PListNode;

   Read_data(fin1,Pa);
   Read_data(fin2,Pb);

   Pc=PolyAdd(Pa,Pb);

   ViewP(Pa);
   cout << "+\n";
   ViewP(Pb);
   cout << "=\n";
   ViewP(Pc);

   FreeAllNode(Pa);
   FreeAllNode(Pb);
   FreeAllNode(Pc);
   system("PAUSE");	
   return EXIT_SUCCESS;
}

PListNode *AddTail(PListNode *tail,float co,int ex)
{
   PListNode *p;
   p=new PListNode;
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
   c=new PListNode;
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
void Read_data(fstream &f,PListNode *Tail)
{
   int expo;
   float coef;

   f >> coef;        /*��ŪŪ�ݫY�Ƥέ���,�Y���F�ɧ�,�Y*/
   f >> expo;        /*��Ū�J���\��~�إߦ��`�I,�_�h�|�y*/
   while(!f.eof())				/*���̫�@����Ʒ|�إߨ⦸*/
   {
	  Tail=AddTail(Tail,coef,expo);
	  f >> coef;      
      f >> expo;  
   }
}

void ViewP(PListNode *p)
{
    p = p->next;
	for(;p->next != NULL;p=p->next)
		cout << p->coef << "X" << p->expo << " + ";
	cout << p->coef << "X" << p->expo << endl;
   
}

void FreeAllNode(PListNode *head)
{
   PListNode *next_node;

   while(head->next != NULL)
   {
	  next_node=head->next;
	  delete head;
	  head=next_node;
   }
   delete head;
}
