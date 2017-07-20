/* 
   3.7�`  �쵲��C����L�B�� 

*/
#include <stdio.h>
#include <stdlib.h>

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
	FILE *fin;
	int insertdata, len;
	if((fin=fopen("List.in","r")) == NULL)
	{
		printf("File can not be opened, program terminate.");
		exit(1);
	}

	listA=(ListNode*)malloc(sizeof(ListNode));
	listA->next=NULL;
	listB=(ListNode*)malloc(sizeof(ListNode));
	listB->next=NULL;

	fscanf(fin,"%d",&insertdata);
	while(!feof(fin))
	{
		InsertTail(listA,insertdata);
		InsertTail(listB,insertdata);
		fscanf(fin,"%d",&insertdata);
	}
	fclose(fin);
	printf("\n The elements of the listA are : \n");
	ListTraverse(listA);
	
	len = ListLength(listA);
	printf("\n The length of the listA is : %d \n",len);
	printf("\n ");
	
	printf("\n The elements of the listB are : \n");
	ListTraverse(listB);
	len = ListLength(listB);
	printf("\n The length of the listB is : %d \n",len);
	printf("\n ");
	ListConcate(listA, listB);
	printf("\n The elements of the listA ( after concatenation ) are : \n");
	ListTraverse(listA);
	printf("\n ");
	FreeAllNode(listA);		/*����Ҧ��`�I*/
	FreeAllNode(listB);		/*����Ҧ��`�I*/  
  
    system("PAUSE");	
    return 0;
}

void ListTraverse( ListNode *head)
{
    ListNode   *p = head;
    p = p->next ;
    while ( p )
    {
		printf("\t%d", p->data );
		p = p->next ;
    }
}

int	ListLength( ListNode *head)
{
	int   counter = 0 ;
	ListNode *p = head ;
	while ( (p=p->next) != NULL) /* �Ŧ�C�ȥ]�t���`�I */
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
   ListNode *next_node;

   while(head != NULL)
   {
	next_node=head->next;
	free(head);
	head=next_node;
   }
}
