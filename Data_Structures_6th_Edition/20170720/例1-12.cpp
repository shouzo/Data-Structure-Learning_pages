/*=========================================================

     例 1-12

        factorial()       求 N 階乘
  =========================================================
*/

#include <cstdlib>
#include <iostream>
using namespace std;

int factor(int);

int main(int argc, char *argv[])
{
    int n;
    int answer;

    cout << "Please input a number no bigger than 12 => ";
    cin >> n;                     //讀入數字

    if(n > 12)                  //因大於12之階乘超出 int 所能表示之範圍
        cout << "The answer will be too large for a long integer.\n";
        
    else if(n < 0)                           //小於零之數不合法
        cout << "Input error,number must > 0";
    else
	{
		answer = factor(n);
		cout << answer << "! = " << answer << "\n ";
	}
    system("PAUSE");
    return EXIT_SUCCESS;

}

//階乘計算函式        
int factor(int n)
{
    int i;
    int result;

    result=1;
    i=1;
    while(i <= n)
    {
        result=result*i;
        i++;
    }
    return result;
}
