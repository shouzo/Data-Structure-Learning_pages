/*=========================================================

      4-6�` �ΰ}�C���c��@��C

	  Enqueue()	�N��Ʀ۫�ݥ[�J
	  Dequeue()	�N��Ʀ۫e�ݧR��

  =========================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM	7

typedef struct tagQueue
	{
	   int item[MAX_ITEM];        /*������*/
	   int	front;
	   int	rear;
	}QUEUE;
QUEUE Que;

void PrintQueue(QUEUE *);
int  Enqueue(QUEUE *,int);
int  Dequeue(QUEUE *,int *);

int main(int argc, char *argv[])
{
   int choose,LoopFlag=1;
   int data;

   Que.front=0;
   Que.rear=0;
   while(LoopFlag)
   {
		printf("\n��C���e�ѫe���:");
		PrintQueue(&Que);
		printf("\n(1)�q��C��ݩ���\n(2)�q��C�e�ݨ����\n(0)����=>");
		scanf("%d",&choose);
		switch(choose)
		{
		case 0:
			LoopFlag=0;			/*�����{��*/
			break;
		case 1:
			printf("�п�J����J�����=>");
			scanf("\n%d",&data);
			if(Enqueue(&Que, data) == 0)
				printf("��C�w��,Enqueue����");
			break;
		case 2:
			if(Dequeue(&Que, &data) == 0)
				printf("��C�w��,Dequeue����");
			else
				printf("���X����Ƭ�=>%d",data);
			break;
		default:
			printf("�ﶵ���~");
		}
   }
   system("PAUSE");	
   return 0;
}

void PrintQueue(QUEUE *q)
{
   int i;
   if (q->front == q->rear)
       return; /* queue empty */
   for (i=(q->front+1)%MAX_ITEM; i != q->rear ; i= (i+1)%MAX_ITEM )
       printf("%d ",q->item[i]);
   printf("%d ",q->item[q->rear]);
}

int Enqueue (QUEUE *q, int x)
{
    if((q->rear+1)%MAX_ITEM == q->front)
	    return (0);
    q->rear=(q->rear+1)% MAX_ITEM;
    q->item [q->rear]=x;
    return (1);
}

int Dequeue (QUEUE *q, int *xptr)
{
    if (q->front == q->rear)
	    return(0);
    q->front = (q->front+1) % MAX_ITEM;
    *xptr = q->item[q->front];
    return 1;
}
