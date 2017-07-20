/*=========================================================

       8-4�`  ����k: �ѨM�I������k: �u�ʱ����k

          hash_init()           �ҩl���禡
          hash_insert()         �w�Ƹ�ƨ禡
          hash()                ������
          hash_srch()           �b�H����s�ƹL����椤�j�M
          is_full()             ���ܰ}�C�Ŷ��O�_�w��
          PrintTable()          �L�X������
          table[m]              ������}�C
          m                     ���j�p

  =========================================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#define         m       13
#define         EMPTY   -32768

int table[m];
int hash(int );
void hash_init(void);
void hash_insert(int);
int  hash_srch(int);
int  is_full(void);
void PrintTable(int []);

int main(int argc, char *argv[])
{
    int in_data,addr;
    int choose, loopflag=1;

    hash_init();

    while(loopflag)
    {
        cout << "������e(e��Ů�): ";
        PrintTable(table);
        cout << endl << "(1)�[�J���\n(2)�j�M���\n(0)����=>";
        cin >> choose;

        switch(choose)
        {
                case 0:
                        loopflag=0;                        /*�����{��*/
						break;
                case 1:
                        if(is_full())
							cout << "�}�C�w��" << endl;
                        else
                        {
							cout << "�п�J���[�J�����=>";
							cin >> in_data;
							hash_insert(in_data);
                        }
                        break;
                case 2:
                        cout << "�п�J���j�M�����=>";
                        cin >> in_data;

                        if((addr=hash_srch(in_data)) == -1)
							cout << "�䤣����" << endl;
                        else
							cout << "��� " << in_data << " ������ " << addr << " �Ӧ�m(��0��_)" << endl;
                        break;
				default:
						cout << "Wrong Input !!!! " << endl;
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
        table[i]= EMPTY;        /*�N��Ů�*/
}


void hash_insert(int key)
{
    int addr=hash(key);         /*�I�s�����Ʊo��m*/
    while(table[addr] != EMPTY)
        addr=(addr+1) % m;      /*�~��A�qtable[0]�}�l*/
    table[addr]=key;
}

/*�j�M��Ȭ�key,���\�Ǧ^����m,���ѶǦ^-1*/
int hash_srch(int key)
{
    int addr;
    addr=hash(key);
    while(table[addr] != key)
    {
        addr=(addr+1)%m;
        if(table[addr]== EMPTY || addr==hash(key))/*�Y�O�Ů�ΤS�^����I*/
			return(-1);                    /*�h�Ǧ^����*/
    }
    return(addr);
}

int is_full(void)
{
    int i;

	for(i=0;i < m;i++)
        if(table[i] == EMPTY)
			return(0);
    return(1);
}

void PrintTable(int a[])
{
	int i;
	for (i=0; i<m; i++)
		if (a[i]!= EMPTY)
			cout << " " << a[i];
		else
			cout << " e ";
}
