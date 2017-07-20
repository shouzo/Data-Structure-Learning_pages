/*=========================================================

    �� 3-6 �`

	  InsertAfter() ���J�`�I
	  DeleteNode()	�R���`�I
	  InsertTail()	���C���ݼW�@�s�`�I
	  GetPreNode()	��M���w�`�I���e�@�`�I
	  PrintList()	�L�X�`�I���e
	  FreeAllNode() ����Ҧ��`�I���O����Ŷ�

  =========================================================
*/

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

typedef struct tagListNode
	{
	   int data;			
	   struct tagListNode *next;
	}ListNode;
ListNode *listA;

int InsertAfter(ListNode *, int );
int DeleteNode(ListNode *,ListNode *);
int InsertTail(ListNode *,int );
ListNode *GetPreNode(ListNode *,ListNode *);
void FreeAllNode(ListNode *);
void PrintList(ListNode *);

int main(int argc, char *argv[])
{
   int choose,i,insertdata,num;
   ListNode *p;
   fstream fin;
   
   fin.open("List.in", ios::in);
   if( !fin)
   {
		cout << "File can not be opened, program terminates.";
		return !EXIT_SUCCESS;
   }

   listA=new ListNode;
   listA->next=NULL;

   fin >> insertdata;
   while(!fin.eof())
   {
		InsertTail(listA,insertdata);
		fin >> insertdata;
   }
   fin.close();
   while(1)
   {
		cout << "\n��C���e( Content of list )=>";
		PrintList(listA);

		cout << "\n(1)���[�`�I(Append new node)\n(2)���J�`�I(Insert new node)\n(3)�R���`�I(Delete node)\n(0)����(exit)=>";
		cin >> choose;

		switch(choose)
		{
		case 0:
			FreeAllNode(listA);		/*����Ҧ��`�I*/
		    system("PAUSE");	
			return 0;			/*�����{��*/
		case 1:
			cout << "�п�J�����[�����(Input new data )=>";
			cin >> insertdata;
			InsertTail(listA,insertdata);
			break;
		case 2:
			cout << "�п�J�����J�����(Input new data)=>";
			cin >> insertdata;

			cout << "�п�J�����J����m(New Position)=>";
			cin >> num;

			for(i=1,p=listA;i!=num && p!=NULL;p=p->next,i++);
			if(p == NULL)
				cout << "���J���� ( Insert Failed )";
			else if(InsertAfter(p,insertdata) == 0)
				cout << "���J���� ( Insert Failed )";
			break;
		case 3:
			cout << "�п�J���R������� ( data to be deleted )=>";
			cin >> num;

			for(i=0,p=listA;p!=NULL&&p->data!=num;p=p->next,i++);
			if(p == NULL)
				cout << "����Ƥ��b��C��( the data is not in list )";
			else if(DeleteNode(listA,p) == 0)
				cout << "�R������( Delete Failed)";
			break;
		default:
			cout << "�ﶵ���~ ( Wrong option ) !!";
		}
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

int InsertAfter(ListNode *p,int value)
{
   ListNode *newnode;
   newnode=new ListNode;
   if (newnode==NULL)
	   return (0);
   newnode->data=value;
   newnode->next=p->next;
   p->next=newnode;
   return(1);
}

int DeleteNode(ListNode *head,ListNode *node)
{
   ListNode *GetPreNode(),*prenode;
   if (head==node)
	   return 0;
   prenode=GetPreNode(head,node);
   if (prenode==NULL)
	   return 0;
   prenode->next=node->next;
   delete node;
   return(1);
}

ListNode *GetPreNode(ListNode *head,ListNode *node)
{
   ListNode *p,*q;
   p=head;
   q=head->next;
   while((q!=NULL) && (q!=node))
   {
	  p=q;
	  q=q->next;
   }
   if(q != NULL)
	  return(p);
   else
	  return(NULL);
}

int InsertTail(ListNode *head,int value)
{
   ListNode *new_node,*p=head;
   if ((new_node=new ListNode) == NULL)
	   return (0);
   new_node->data=value;
   new_node->next=NULL;
   while(p->next != NULL)
	    p=p->next;
   p->next=new_node;
   return (1);
}

void PrintList(ListNode *p)
{
   for(p=p->next;p != NULL;p=p->next)
       cout << p->data << " ";
}

void FreeAllNode(ListNode *head)
{
   ListNode *next_node;

   while(head != NULL)
   {
	   next_node=head->next;
	   delete head;
	   head=next_node;
   }
}
