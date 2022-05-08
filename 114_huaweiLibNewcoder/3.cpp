#include <iostream>
// #include <string>
// #include <vector>
#include <algorithm>
// #include <cmath>
#include <cstdio>
using namespace std;

/**
 * 令 Pi 表示第 i 个素数。现任给两个正整数 M≤N≤10^4，请输出 PM 到 PN 的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 PM 到 PN 的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27

输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/
/**
 * 
 * */

int main(){
  int m,n;
  int i,j,f,q;
  scanf("%d%d",&m,&n);
  // 1不算素数，从2开始
  i=2;
  f=1;  // 总的素数个数
  q=0;  // 打印的素数的个数
  while(f <= n){  // 最多n个
    // 寻找素数
    for(j=2;j*j<=i;j++)  // 最大到j*j=i
      if(i%j==0) break; // 判断i是不是素数
    // 打印符合要求的素数
    if(j*j>i){  // 打印这个素数
      if(q%10>0)  // 非首和尾
        printf(" ");
      if(q > 0 && q % 10 == 0)  // 尾
        printf("\n");
      if(f >= m) {
        printf("%d",i);
        q++;    
      }
      f++;
    }
    i++;
  }
  printf("\n");
  return 0;

}
