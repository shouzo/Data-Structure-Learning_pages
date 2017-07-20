/*=========================================================

    第 3-6 節:
     
=========================================================*/

#include	<stdio.h>
#include	<stdlib.h>



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
	
	printf("\n The elements of the list are : \n");
	ListTraverse(&Head);
	printf("\n ");
	len = ListLength(&Head);
	printf("\n The length of the list is : %d \n",len);
	FreeAllNode(&Head);		/*釋放所有節點*/
    system("PAUSE");	
    return 0;
}

ListNode *CreateList(void)
{
    FILE *fin;
    ListNode Head;
    Head.next = NULL;
    
	int insertdata, len;
	if((fin=fopen("List.in","r")) == NULL)
	{
		printf("File can not be opened, program terminate.");
		return(NULL);
	}

	fscanf(fin,"%d",&insertdata);
	while(!feof(fin))
	{
		InsertTail(&Head,insertdata);
		fscanf(fin,"%d",&insertdata);
	}
	fclose(fin);
    return Head.next;
}

void ListTraverse( ListNode *head)
{
    ListNode   *p = head;
    
    p = p->next ;
    while ( p )
    {
	     printf( "\n%d", p->data );
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
   if ((new_node=(ListNode*)malloc(sizeof(ListNode))) == NULL)
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
	   free(head);
	   head=next_node;
   }
}
