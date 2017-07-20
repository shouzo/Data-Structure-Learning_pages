/*=========================================================

      4-6�`  �ΰ}�C���c��@��C

	  Enqueue()	�N��Ʀ۫�ݥ[�J
	  Dequeue()	�N��Ʀ۫e�ݧR��

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX_ITEM	7

typedef struct tagQueue
	{
	   int item[MAX_ITEM];        //���
	   int	front;
	   int	rear;
	}QUEUE;
QUEUE Que;

void PrintQueue(QUEUE &);
int  Enqueue(QUEUE &, int);
int  Dequeue(QUEUE &, int &);

int main(int argc, char *argv[])
{
   int choose,LoopFlag=1;
   int data;

   Que.front=0;
   Que.rear=0;
   while(LoopFlag)
   {
		cout << "\n��C���e�ѫe���: ";
		PrintQueue(Que);
		cout << "\n(1)�q��C��ݩ���\n(2)�q��C�e�ݨ����\n(0)���� => ";
		cin >> choose;
		switch(choose)
		{
		case 0:
			LoopFlag=0;			/*�����{��*/
			break;
		case 1:
			cout << "�п�J����J�����=> ";
			cin >> data;
			if(Enqueue(Que, data) == 0)
				cout << "��C�w��,Enqueue���� \n";
			break;
		case 2:
			if(Dequeue(Que, data) == 0)
				cout << "��C�w��,Dequeue���� \n ";
			else
				cout << "���X����Ƭ� => " << data << "\n";
			break;
		default:
			cout << "�ﶵ���~\n";
		}
   }
   system("PAUSE");
   return EXIT_SUCCESS;
}

void PrintQueue(QUEUE &q)
{
   int i;
   if (q.front == q.rear)
       return; /* queue empty */
   for (i=(q.front+1)%MAX_ITEM; i != q.rear ; i= (i+1)%MAX_ITEM )
        cout << "  " << q.item[i];
   cout << "  " << q.item[q.rear];
}

int Enqueue (QUEUE &q, int x)
{
    if((q.rear+1)%MAX_ITEM == q.front)
	return (0);
    q.rear=(q.rear+1)% MAX_ITEM;
    q.item [q.rear]=x;
    return (1);
}

int Dequeue (QUEUE &q, int &x)
{
    if (q.front == q.rear)
	return(0);
    q.front = (q.front+1) % MAX_ITEM;
    x = q.item[q.front];
    return 1;
}
