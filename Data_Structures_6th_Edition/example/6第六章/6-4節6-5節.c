/*=========================================================

       6-4�`    �G���𪺫إ�
       6-5�`    �G���𪺨��X

          *Create_BinTree()     �G����إߨ禡
          preorder()            �e�Ǩ��X�禡
          inorder()             ���Ǩ��X�禡
          postorder()           ��Ǩ��X�禡
          visit()               ���X�`�I
          visit2()              ���X�`�I���K�N�O�������^
                                ���ҧQ�Ϋ�ǫ��X�ɤ@�@�N
                                �l��ҥe���O�������^
      
  =========================================================
*/

#include    <stdio.h>
#include    <malloc.h>
#include    <conio.h>
#include	<stdlib.h>

typedef struct Tnode
        {
                struct Tnode *left_c;
                char    data;
                struct Tnode *right_c;
        }TNode;

TNode *Create_BinTree(void);
void preorder(TNode *);
void inorder(TNode *);
void postorder(TNode *);

int main(int argc, char *argv[])
{
    TNode *tree;

    printf("��J�`�I��� (�Ҧp ab00c00 ): \n");
    tree=Create_BinTree();

    printf("\n�e�Ǩ��X���G=> ");
    preorder(tree);

    printf("\n���Ǩ��X���G=> ");
    inorder(tree);

    printf("\n��Ǩ��X���G=> ");
    postorder(tree);
	printf("\n");
	system("PAUSE");
    return EXIT_SUCCESS;
}

TNode *Create_BinTree(void)
{
    TNode *ptr;
    char data;
    data = getche();
    if(data == '0')
        return (NULL);
    ptr=(TNode *)malloc(sizeof(TNode));
    ptr->data=data;
    ptr->left_c=Create_BinTree();
    ptr->right_c=Create_BinTree();
    return(ptr);
}

void visit(TNode *p)
{
    printf("%c ",p->data);
}

/*��Ǩ��X��*/
void visit2(TNode *p)
{
    printf("%c ",p->data);
    free(p);
}

void preorder(TNode *p)
{
    if(p != NULL)
    {
        visit(p);
        preorder(p->left_c);
        preorder(p->right_c);
    }
}

void inorder(TNode *p)
{
    if(p != NULL)
    {
        inorder(p->left_c);
        visit(p);
        inorder(p->right_c);
    }
}

void postorder(TNode *p)
{
   if(p != NULL)
   {
        postorder(p->left_c);
        postorder(p->right_c);
        visit2(p);
   }
}
