/*=========================================================
	4-4-2�`

     ���|������:�B�⦡�ഫ�ΨD��
	    ��������
	    ��Ǧ��D��

	  in_to_post()	��������
	  priority()	�P�_�B�⤸���u������
	  post_evaluate()��Ǧ��D��
	  evaluate()	�@���w�B�⤸�p��
	  Push()	���J���|
	  Pop() 	�۰��|�u�X���

  =========================================================
*/
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX_OP 5
#define operator(c) ((c=='+')||(c=='-')||(c=='*')||(c=='/'))?1:0
#define operands(c) ((c)>='a' && (c)<='z')?1:0
#define MAX_ITEM 100
typedef struct tagSTACK
	{
		int item [MAX_ITEM];
		int top;
	}STACK;
STACK S;

char op[MAX_OP]={'(','+','-','*','/'};
char prio[MAX_OP]={0,1,1,2,2};
int op_value[26]={10,30,6,9,8,11,12,13,7,8,22,56,77,76,
		   55,56,43,40,13,19,18,16,46,52,61,63};

void	in_to_post(char *,char *);
void	Push(int);
void	Pop(int *);
int		post_evaluate(char *);
int		evaluate(char ,int ,int );
int		priority(int );

int main(int argc, char *argv[])
{
    int i;
    char infix[MAX_ITEM];
    char postfix[MAX_ITEM];

    S.top=-1;

    cout << " �п�J���Ǧ�, �Ҧp (a+b)*c-d/e : ";
    cin >> infix;
    in_to_post(infix,postfix);
    cout << " ���Ǧ� => " << infix << "\n��Ǧ�=> " << postfix;

    cout << "\n�Y a ~ z ���Ȥ��O�O=> ";
    for(i=0;i <26;i++)
		cout << op_value[i] << "  " ;
    cout << "\n�W�������G= " << post_evaluate(postfix) << "\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void in_to_post(char *infix,char *postfix)
{
    int i,j,element;
    char token;
    
    i=j=0;
    while((token=infix[i]) != '\0')
    {
	i=i+1;
	if(operands(token))
		postfix [j++]=token;
	else if(token == '(')
		Push(token);
	else if(token == ')')
		while (S.top >= 0)
		{
			Pop(&element);
			if(element == '(')
				break;
			postfix [j++]=element;
		}
	else if(operator(token))
	{
		while(S.top >= 0)
		{
			element=S.item[S.top];
			if(priority(token) <= priority (element))
			{
				Pop(&element);
				postfix[j++]=element;
			}
			else
				break;
		}
		Push(token);
	}
    }
    while(S.top >= 0)
    {
		Pop(& element);
		postfix[j++]=element;
    }
    postfix[j]='\0';
}

void Push(int x)
{
    if (S.top < MAX_ITEM-1)
    {
		S.top++;
		S.item[S.top]=x;
    }
}
void Pop(int *x)
{
    if (S.top >= 0)
    {
		*x=S.item[S.top];
		S.top--;
    }
}

int priority(int c)
{
    int i=0;
	for(;i < MAX_OP;i++)
		if(op[i] == c)
			return(prio [i]);
    return(-1);
}


int post_evaluate(char *postfix)
{
    char token;
    int op1,op2,result,i=0;

    while((token=postfix[i]) != '\0')
    {
	i=i+1;
	if(operands(token))
		Push(op_value[token-'a']);
	else if(operator(token))
	{
		Pop(&op2);
		Pop(&op1);
		result=evaluate(token,op1,op2);
		Push(result);
	}
    }
    Pop (&result);
    return(result);
}
int evaluate(char optr,int op1,int op2)
{
    int result;
    switch(optr)
    {
	case '+':result=op1+op2;
		 break;
	case '-':result=op1-op2;
		 break;
	case '*':result=op1*op2;
		 break;
	case '/':result=op1/op2;
		 break;
    }
    return(result);
}
