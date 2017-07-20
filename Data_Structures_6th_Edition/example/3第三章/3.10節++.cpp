/*=========================================================

    第3-10節: 鏈結串列的應用 -- 多項式的加法
		
	  InsertAfter() 插入節點
	  DeleteNode()	刪除節點
	  Read_data()	自指定檔案讀入資料
	  ViewP()	印出多項式
	  FreeAllNode() 釋放所有節點之記憶體空間

  =========================================================
*/

#include <cstdlib>
#include <iostream>
#include <fstream> 

using namespace std;

typedef struct tagPListNode
	{
	   float coef;			/*係數*/
	   int	 expo;			/*冪次*/
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
	   cout << "開檔失敗,結束程式";
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

   f >> coef;        /*先讀讀看係數及乘冪,若未達檔尾,即*/
   f >> expo;        /*都讀入成功後才建立此節點,否則會造*/
   while(!f.eof())				/*成最後一筆資料會建立兩次*/
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
