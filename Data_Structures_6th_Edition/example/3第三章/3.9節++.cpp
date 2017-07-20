/*=========================================================

    3-9 節  雙向鏈結串列
		
		 
	  InsertAfter() 插入節點
	  DeleteNode()	刪除節點
	  PrintLIst()	 印出節點內容
	  FreeAllNode() 釋放所有節點之記憶體空間

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
    {	cout << "開檔失敗,結束程式 (File can not be opened, program terminates.)";
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
		cout << "\n環狀雙向鏈結串列內容( Content of circular doubly linked list )=>\n";
		PrintList(listA);
		cout <<"\n(1)附加節點(Append new node)\n(2)插入節點(Insert new node)\n(3)刪除節點(Delete node)\n(0)結束(exit)=>";
		cin >> choose;
		switch(choose)
		{
		case 0:
			FreeAllNode(listA);		/*釋放所有節點*/
			system("PAUSE");
			return EXIT_SUCCESS;			/*結束程式*/
		case 1:
			cout << "請輸入欲附加之資料(Input new data )=>";
			cin >> insertdata;

			for(p=listA;p->right != listA;p=p->right);
			InsertAfter(p,insertdata);
			break;
		case 2:
			cout << "請輸入欲插入之資料(Input new data )=>";
			cin >> insertdata;

			cout << "請輸入欲插入之位置(New Position)=>";
			cin >> num;

			for(i=1,p=listA;i!=num && p->right!=listA;p=p->right,i++);
			if(p == NULL)
				cout << "插入失敗( Insert Failed )";
			else if(InsertAfter(p,insertdata) == 0)
				cout << "插入失敗( Insert Failed )";
			break;
		case 3:
			cout << "請輸入欲刪除之資料 ( data to be deleted )=>";
			cin >> num;

			for(i=0,p=listA->right;p!=listA && p->data!=num ;p=p->right,i++);
			if(p == listA)
				cout << "此資料不在串列中( the data is not in list )";
			else if(DeleteNode(p) == 0)
				cout << "刪除失敗( Delete Failed)";
			break;
		default:
			cout << "選項錯誤 ( Wrong option )";
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
