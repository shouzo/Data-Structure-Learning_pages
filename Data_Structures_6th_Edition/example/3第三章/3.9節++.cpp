/*=========================================================

    3-9 �`  ���V�쵲��C
		
		 
	  InsertAfter() ���J�`�I
	  DeleteNode()	�R���`�I
	  PrintLIst()	 �L�X�`�I���e
	  FreeAllNode() ����Ҧ��`�I���O����Ŷ�

  =========================================================
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
 
using namespace std;

typedef struct tagDListNode
	{
	   struct tagDListNode *left;
	   int	  data;
	   struct tagDListNode *right;
	}DListNode;

int		InsertAfter(DListNode *,int);
int		DeleteNode(DListNode *);
void	FreeAllNode(DListNode *);
void	PrintList(DListNode *);

int main(int argc, char *argv[])
{
    int choose,i,insertdata,num;
	DListNode *p;
	DListNode *listA;
	fstream fin;
	listA= new DListNode;
	listA->left=listA;
	listA->right=listA;
	p=listA;

    fin.open("List.in", ios::in);
    if(!fin)
    {	cout << "�}�ɥ���,�����{�� (File can not be opened, program terminates.)";
        return !EXIT_SUCCESS;	
    }
	fin >> insertdata;
	while(!fin.eof())
	{
		InsertAfter(p,insertdata);
		p=p->right;
		fin >> insertdata;
	}
	fin.close();
	while(1)
	{
		cout << "\n�������V�쵲��C���e( Content of circular doubly linked list )=>\n";
		PrintList(listA);
		cout <<"\n(1)���[�`�I(Append new node)\n(2)���J�`�I(Insert new node)\n(3)�R���`�I(Delete node)\n(0)����(exit)=>";
		cin >> choose;
		switch(choose)
		{
		case 0:
			FreeAllNode(listA);		/*����Ҧ��`�I*/
			system("PAUSE");
			return EXIT_SUCCESS;			/*�����{��*/
		case 1:
			cout << "�п�J�����[�����(Input new data )=>";
			cin >> insertdata;

			for(p=listA;p->right != listA;p=p->right);
			InsertAfter(p,insertdata);
			break;
		case 2:
			cout << "�п�J�����J�����(Input new data )=>";
			cin >> insertdata;

			cout << "�п�J�����J����m(New Position)=>";
			cin >> num;

			for(i=1,p=listA;i!=num && p->right!=listA;p=p->right,i++);
			if(p == NULL)
				cout << "���J����( Insert Failed )";
			else if(InsertAfter(p,insertdata) == 0)
				cout << "���J����( Insert Failed )";
			break;
		case 3:
			cout << "�п�J���R������� ( data to be deleted )=>";
			cin >> num;

			for(i=0,p=listA->right;p!=listA && p->data!=num ;p=p->right,i++);
			if(p == listA)
				cout << "����Ƥ��b��C��( the data is not in list )";
			else if(DeleteNode(p) == 0)
				cout << "�R������( Delete Failed)";
			break;
		default:
			cout << "�ﶵ���~ ( Wrong option )";
		}
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

int InsertAfter(DListNode *p,int value)
{
   DListNode *newnode;
   newnode=new DListNode;
   if(newnode == NULL)
		return 0;
   newnode->data=value;
   newnode->left=p;
   newnode->right=p->right;
   p->right->left=newnode;
   p->right=newnode;
   return 1;
}

int DeleteNode(DListNode *p)
{
   if(p == NULL)
		return(0);
   p->left->right=p->right;
   p->right->left=p->left;
   delete p;
   return 1;
}

void PrintList(DListNode *head)
{
	DListNode *p=head;
	for(p=p->right;p != head;p=p->right)
		cout << p->data << "  ";
}

void FreeAllNode(DListNode *head)
{
   DListNode *CurrentNode=head->right,*NextNode;

   while(CurrentNode != head)
   {
		NextNode=CurrentNode->right;
		delete CurrentNode;
		CurrentNode=NextNode;
   }
   delete head;
}
