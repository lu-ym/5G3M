#include <iostream>
// #include <string>
// #include <vector>
#include <algorithm>
// #include <cmath>
#include <cstdio>
using namespace std;

/**
 * 华老师给了你们一个打印任务，让你们打印边长为n的菱形。

输入格式:

输入一行一个整数n（1<=n<=50)。

输出格式：

打印边长为N的菱形（菱形的打印形式见样例），每行均以’'结尾，每行的’’之前如果需要用空格
	补齐对齐，’*’之后不要有多余的空格。

输入样例：

6

输出样例：

*/
/**
 * 题目中要求为打印边长为n的菱形。
下面为边长为5和边长为6的菱形，为了更加直观的看到规律，结果中空格用#代替。
在此题目中边长为n其实可以理解为从第一行到最多点行的行数，那么我们就可以根据当前行数来
	控制输出的*与 （空格）。

从上面的结果中，我们发现：
第一行会先输出n-1个空格，再输出1（行数 2 * i - 1 ）个*；
第二行先输出 n-2 个空格，再输出3（行数 2 * i - 1）个*；
那么第n行则会先输出 n-n 个空格，再输出2 * n - 1个*。
n行之后的行与之前的输出规则与上述部分相反，即：
n+1行，先输出 1 个空格，再输出 2 * (n-1)-1 个 *；
n+2行，先输出 2 个空格，再输出 2 * (n-2)-1 个 *；
······
2n-1行（最后一行），先输出n-1个空格，再输出 2 * (n-n+1)-1 个*。
 * */

int main()
{
	int i = 1, j, k, n;
	cin >> n;//输入n
  //先输出菱形的上半部分
	for (; i <= n; i++)	{
		for (j = 1; j <= (n - i); j++){
			cout << " ";//先输出空格
		}
		for (k = 1; k <= 2 * i - 1; k++){
			cout << "*";//再输出*
		}
		// cout << '\n';
		cout << endl;
	}
	for (i = 1; i <= n - 1; i++){  // 菱形下半部分
		for (j = 1; j <= i; j++){
      cout << ' ';//先输出空格
    }
		for (k = 1; k <= 2*(n - i)-1; k++){
      cout << "*";//再输出*
    }
		cout << endl;
	}
	return 0;
}