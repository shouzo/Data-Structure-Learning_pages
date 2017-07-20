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

#include	<stdio.h>
#include	<stdlib.h>

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
   FILE *fin;
   if((fin=fopen("List.in","r")) == NULL)
   {
		printf("File can not be opened, program terminates.");
		return 1;
   }

   listA=(ListNode*)malloc(sizeof(ListNode));
   listA->next=NULL;

   fscanf(fin,"%d",&insertdata);
   while(!feof(fin))
   {
		InsertTail(listA,insertdata);
		fscanf(fin,"%d",&insertdata);
   }
   fclose(fin);
   while(1)
   {
		printf("\n��C���e( Content of list )=>");
		PrintList(listA);

		printf("\n(1)���[�`�I(Append new node)\n(2)���J�`�I(Insert new node)\n(3)�R���`�I(Delete node)\n(0)����(exit)=>");
		scanf("%d",&choose);

		switch(choose)
		{
		case 0:
			FreeAllNode(listA);		/*����Ҧ��`�I*/
		    system("PAUSE");	
			return 0;			/*�����{��*/
		case 1:
			printf("�п�J�����[�����(Input new data )=>");
			scanf("%d",&insertdata);
			InsertTail(listA,insertdata);
			break;
		case 2:
			printf("�п�J�����J�����(Input new data)=>");
			scanf("%d",&insertdata);

			printf("�п�J�����J����m(New Position)=>");
			scanf("%d",&num);

			for(i=1,p=listA;i!=num && p!=NULL;p=p->next,i++);
			if(p == NULL)
				printf("���J���� ( Insert Failed )");
			else if(InsertAfter(p,insertdata) == 0)
				printf("���J���� ( Insert Failed )");
			break;
		case 3:
			printf("�п�J���R������� ( data to be deleted )=>");
			scanf("%d",&num);

			for(i=0,p=listA;p!=NULL&&p->data!=num;p=p->next,i++);
			if(p == NULL)
				printf("����Ƥ��b��C��( the data is not in list )");
			else if(DeleteNode(listA,p) == 0)
				printf("�R������( Delete Failed)");
			break;
		default:
			printf("�ﶵ���~ ( Wrong option ) !!");
		}
   }
   system("PAUSE");	
   return 0;
}

int InsertAfter(ListNode *p,int value)
{
   ListNode *newnode;
   newnode=(ListNode*)malloc(sizeof(ListNode));
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
   free(node);
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
   if ((new_node=(ListNode*)malloc(sizeof(ListNode))) == NULL)
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
       printf("%d ",p->data);
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
