#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

/*  宣告節點結構 */
typedef struct tagListNode
{
     int data;		
     struct tagListNode *next;
}ListNode;

ListNode *CreateList(void);
int InsertTail(ListNode *,int );
int	ListLength( ListNode *);
void ListTraverse( ListNode *);
void FreeAllNode(ListNode *);

int main(int argc, char *argv[])
{
    int insertdata, len;
    ListNode Head;
    
	Head.next = CreateList();
	
	cout << "\n The elements of the list are : \n";
	ListTraverse(&Head);
	cout << "\n ";
	len = ListLength(&Head);
	cout << "\n The length of the list is :" << len << " \n";
	FreeAllNode(&Head);		/*釋放所有節點*/
    system("PAUSE");
    return EXIT_SUCCESS;
}

ListNode *CreateList(void)
{
    fstream fin;
    ListNode Head;
    Head.next = NULL;
    
	int insertdata, len;
	
	fin.open("List.in",ios::in);
	if(!fin )
	{
		cout << "File can not be opened, program terminated.";
		return(NULL);
	}
    
    fin >> insertdata;
	while(!fin.eof())
	{
        InsertTail(&Head,insertdata);
		fin >> insertdata;
	}
	fin.close();
    return Head.next;
}

void ListTraverse( ListNode *head)
{
    ListNode   *p = head;
    
    p = p->next ;
    while ( p )
    {
	     cout << endl << p->data;
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

void FreeAllNode(ListNode *head)
{
   ListNode *next_node = head->next;

   while(head != NULL)
   {
       next_node=head->next;
	   delete head;
	   head=next_node;
   }
}
