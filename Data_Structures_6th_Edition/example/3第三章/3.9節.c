/*=========================================================

    3-9 �`  ���V�쵲��C
		
		 
	  InsertAfter() ���J�`�I
	  DeleteNode()	�R���`�I
	  PrintLIst()	 �L�X�`�I���e
	  FreeAllNode() ����Ҧ��`�I���O����Ŷ�

  =========================================================
*/
#include <stdio.h>
#include <stdlib.h>

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
	FILE *fin;
	listA=(DListNode*)malloc(sizeof(DListNode));
	listA->left=listA;
	listA->right=listA;
	p=listA;

    if((fin=fopen("List.in","r")) == NULL)
    {	printf("�}�ɥ���,�����{�� (File can not be opened, program terminate.)");
        return 1;	
    }
	fscanf(fin,"%d",&insertdata);
	while(!feof(fin))
	{
		InsertAfter(p,insertdata);
		p=p->right;
		fscanf(fin,"%d",&insertdata);
	}
	fclose(fin);
	while(1)
	{
		printf("\n�������V�쵲��C���e( Content of circular doubly linked list )=>\n");
		PrintList(listA);
		printf("\n(1)���[�`�I(Append new node)\n(2)���J�`�I(Insert new node)\n(3)�R���`�I(Delete node)\n(0)����(exit)=>");
		scanf("%d",&choose);
		switch(choose)
		{
		case 0:
			FreeAllNode(listA);		/*����Ҧ��`�I*/
			exit(0);			/*�����{��*/
		case 1:
			printf("�п�J�����[�����(Input new data )=>");
			scanf("%d",&insertdata);

			for(p=listA;p->right != listA;p=p->right);
			InsertAfter(p,insertdata);
			break;
		case 2:
			printf("�п�J�����J�����(Input new data )=>");
			scanf("%d",&insertdata);

			printf("�п�J�����J����m(New Position)=>");
			scanf("%d",&num);

			for(i=1,p=listA;i!=num && p->right!=listA;p=p->right,i++);
			if(p == NULL)
				printf("���J����( Insert Failed )");
			else if(InsertAfter(p,insertdata) == 0)
				printf("���J����( Insert Failed )");
			break;
		case 3:
			printf("�п�J���R������� ( data to be deleted )=>");
			scanf("%d",&num);

			for(i=0,p=listA->right;p!=listA && p->data!=num ;p=p->right,i++);
			if(p == listA)
				printf("����Ƥ��b��C��( the data is not in list )");
			else if(DeleteNode(p) == 0)
				printf("�R������( Delete Failed)");
			break;
		default:
			printf("�ﶵ���~ ( Wrong option )");
		}
    }
   
    system("PAUSE");	
    return 0;
}

int InsertAfter(DListNode *p,int value)
{
   DListNode *newnode;
   newnode=(DListNode*)malloc(sizeof(DListNode));
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
   free(p);
   return 1;
}

void PrintList(DListNode *head)
{
	DListNode *p=head;
	for(p=p->right;p != head;p=p->right)
		printf("%d ",p->data);
}

void FreeAllNode(DListNode *head)
{
   DListNode *CurrentNode=head->right,*NextNode;

   while(CurrentNode != head)
   {
		NextNode=CurrentNode->right;
		free(CurrentNode);
		CurrentNode=NextNode;
   }
   free(head);
}
