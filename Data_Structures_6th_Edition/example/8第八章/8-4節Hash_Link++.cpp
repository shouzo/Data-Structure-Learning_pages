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

#include <cstdlib>
#include <iostream>

using namespace std;

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
int list_insert_tail(int ,int );

int main(int argc, char *argv[])
{
	int in_data,choose, addr,loopflag=1;

    hash_init();

    while(loopflag)
    {
        cout << "������e:" << endl;
        PrintTable();
        cout << endl << "\n(1)�[�J���\n(2)�j�M���\n(0)����=>";
        cin >> choose;

        switch(choose)
        {
                case 0:
                        Free_All_Node();
                        loopflag=0;                        /*�����{��*/
						break;
                case 1:
                        cout << "�п�J���[�J�����=>";
                        cin >> in_data;

                        hash_insert(in_data);
                        break;
                case 2:
                        cout << "�п�J���j�M�����=>";
                        cin >> in_data;

                        if((addr=hash_srch(in_data)) == -1)
							cout << "�䤣����" << endl;
                        else
							cout << "���! �b�� " << addr << " �Ӧ�C !" << endl;
                        break;
                default:
                        cout << "�ﶵ���~" << endl ;
        }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
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
   if ((new_node=new ListNode) == NULL)
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
	cout << "table[" << n << "]: ";
	if (p->key != EMPTY)
	cout << p->key << " , ";
	p=p->next;
	while(p != NULL )
    {
		cout << p->key << " , ";
		p=p->next;
    }
	cout << endl;
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
			delete p;
			p=q;
        }
    }
}
