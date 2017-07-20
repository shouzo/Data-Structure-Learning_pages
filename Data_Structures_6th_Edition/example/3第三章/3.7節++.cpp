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

int InsertTail(ListNode *,int );
int	ListLength( ListNode *);
void  ListConcate( ListNode *, ListNode *);
void ListTraverse( ListNode *);
void FreeAllNode(ListNode *);

int main(int argc, char *argv[])
{
    ListNode *listA,*listB;
	fstream fin;
	int insertdata, len;
    
    fin.open("List.in",ios::in);
	if(!fin)
	{
		cout << "File can not be opened, program terminates.";
		return 1;
	}

	listA = new ListNode;
	listA->next = NULL;
	listB = new ListNode;
	listB->next = NULL;

	fin >> insertdata;
	while(!fin.eof())
	{
		InsertTail(listA,insertdata);
		InsertTail(listB,insertdata);
		fin >> insertdata;
	}
	fin.close();
	cout << "\n The elements of the listA are : \n";
	ListTraverse(listA);
	
	len = ListLength(listA);
	cout << "\n The length of the listA is : " << len << endl;
		
	cout << "\n The elements of the listB are : \n";
	ListTraverse(listB);
	len = ListLength(listB);
	cout << "\n The length of the listB is : " << len << endl;
	
    ListConcate(listA, listB);
	cout << "\n The elements of the listA ( after concatenation ) are : \n";
	ListTraverse(listA);
	cout << endl;
	FreeAllNode(listA);		/*釋放所有節點*/
	FreeAllNode(listB);		/*釋放所有節點*/  
    system("PAUSE");
    return EXIT_SUCCESS;
}

void ListTraverse( ListNode *head)
{
    ListNode   *p = head;
    p = p->next ;
    while ( p )
    {
		cout << "\t" << p->data ;
		p = p->next ;
    }
}

int	ListLength( ListNode *head)
{
	int   counter = 0 ;
	ListNode *p = head ;
	while ( (p=p->next) != NULL)
	   counter ++ ;
	return counter ;
}

void  ListConcate( ListNode *listA, ListNode *listB)
{
	ListNode *p = listA ;
	while ( p->next != NULL)
	    p = p->next ;
	p->next = listB->next ;
	listB->next = NULL ;
}

int InsertTail(ListNode *head,int value)
{
   ListNode *new_node,*p=head;
   if ((new_node= new ListNode) == NULL)
	    return (0);
   new_node->data=value;
   new_node->next=NULL;
   while(p->next != NULL)
	    p=p->next;
   p->next=new_node;
   return (1);
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
