/*=========================================================

     4-8節 例4.6: 遞迴 : 河內塔問題

	  hanoi()   把 n 個盤子,從 form 柱,經由 by 柱,搬往 to 柱

  =========================================================
*/
#include <cstdlib>
#include <iostream>

using namespace std;

void hanoi(int , char , char , char );

int main(int argc, char *argv[])
{
    int n;
    
	cout << "Please input number => ";
    cin >> n;                     //讀入數字

    if(n > 20) 			
    {					
		cout << "The calucation time will be too long to wait...";
		return !EXIT_SUCCESS;
    }
    if(n < 0)				//小於零之數不合法
    {
		cout << "input error,number must > 0";
		return !EXIT_SUCCESS;
    }
    hanoi(n,'A','B','C');
    cout << "結束\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*把 n 個盤子,從 form 柱,經由 by 柱,搬往 to 柱*/
void hanoi(int n, char from, char by, char to)
{
    if(n > 0)
    {
		hanoi(n-1, from, to, by);
		cout << "move disk no. " << n << " from " << from << " to " << to << "\n" ;
		hanoi(n-1, by, from, to);
    }
}
