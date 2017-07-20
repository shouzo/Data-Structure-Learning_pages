/*=========================================================

       8-4�` ����k: �ѨM�I������k : ���O�쵲�k

          hash_init()           �ҩl���禡
          hash_insert()         �w�Ƹ�ƨ禡
          list_insert_tail()    �I���ɫإ��쵲
          hash()                ������
          hash_srch()           �b�H����s�ƹL����椤�j�M
          Free_All_Node()       �N�Ҧ��O�ЪŶ����^
          table[m]              ��ƪ��}�C
          m                     ��Ƽƥ�(�}�C�j�p)

  =========================================================
*/

#include    <stdio.h>
#include	<stdlib.h>
#include    <malloc.h>

#define         m       13
#define         EMPTY   -32768

typedef struct taglistnode
        {
			int key;
			struct taglistnode *next;
        }ListNode;

ListNode table[m];

int hash(int);
void hash_init(void);
void hash_insert(int);
void Free_All_Node(void);
int  hash_srch(int);
void PrintList(int);
void PrintTable(void);
int  list_insert_tail(int,int);

int main(int argc, char *argv[])
{
	int in_data,choose, addr, loopflag=1;

    hash_init();

    while(loopflag)
    {
        printf("������e:\n");
        PrintTable();
        printf("\n(1)�[�J���\n(2)�j�M���\n(0)����=>");
        scanf("%d",&choose);

        switch(choose)
        {
                case 0:
                        Free_All_Node();
                        loopflag=0;                        /*�����{��*/
						break;
                case 1:
                        printf("�п�J���[�J�����=>");
                        scanf("%d",&in_data);

                        hash_insert(in_data);
                        break;
                case 2:
                        printf("�п�J���j�M�����=>");
                        scanf("%d",&in_data);

                        if((addr=hash_srch(in_data)) == -1)
							printf("�䤣����\n");
                        else
							printf("���! �b�� %d �Ӧ�C\n",addr);
                        break;
                default:
                        printf("�ﶵ���~");
        }
    }
    system("PAUSE");
    return 0;
}

/*������*/
int hash(int key)
{
    return(key % m);
}


void hash_init(void)
{
    int i;
    for(i=0;i < m;i++)
        table[i].key=EMPTY;     /*�N��Ů�*/
        table[i].next=NULL;
}


void hash_insert(int key)
{
    int addr;

    addr=hash(key);             /*�I�s�����Ʊo��m*/
    if(table[addr].key != EMPTY)
        list_insert_tail(addr,key);
    else
        table[addr].key=key;
}


int list_insert_tail(int addr,int key)
{
   ListNode *p,*new_node;
   p=&table[addr];
   while(p->next != NULL)
        p=p->next;
   if ((new_node=(ListNode*)malloc(sizeof(ListNode))) == NULL)
        return (0);
   new_node->key=key;
   new_node->next=NULL;
   p->next=new_node;
   return (1);
}

/*�j�M��Ȭ�key,���\�Ǧ^0,���ѶǦ^-1*/
int hash_srch(int key)
{
    int addr=hash(key);
    ListNode *p;

    p=&table[addr];
    while(p->key != key)
        if(p->next == NULL)
			return(-1);
        else
			p=p->next;

    return(addr);
}

void PrintList(int n)
{
   ListNode  *p;

   p=&table[n];
   printf("table[%d]: ",n);
   if (p->key != EMPTY)
      printf("%d , ",p->key);

   while(p->next != NULL )
    {
      printf("%d , ",p->next->key);
      p=p->next;
    }
   printf("\n");
}

void PrintTable(void)
{
   int  i;

   for (i=0; i<m; i++)
     PrintList(i);
}

void Free_All_Node(void)
{
    ListNode *p,*q;
    int i;

    for(i=0;i < m;i++)
    {
        p=&table[i];
		p = p->next;
        while(p != NULL)
        {
			q=p->next;
			free(p);
			p=q;
        }
    }
}
