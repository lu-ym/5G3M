// #include <iostream>
// // #include <string>
// // #include <vector>
// #include <algorithm>
// // #include <cmath>
// #include <cstdio>
// using namespace std;

/**
 * 方阵的主对角线之上称为“上三角”。
请你设计一个用于填充n阶方阵的上三角区域的程序。填充的规则是：使用1，2，3….的自然数列，
  从左上角开始，按照顺时针方向螺旋填充。
例如：当n=3时，输出：
1 2 3
6 4
5
当n=4时，输出：
1  2  3  4
9 10 5
8  6
7
当n=5时，输出：
1  2  3  4  5
12 13 14 6 
11 15 7
10 8
9
程序运行时，要求用户输入整数n（3~20）
程序输出：方阵的上三角部分。
要求格式：每个数据宽度为4，右对齐。
*/
/**
 * 
 * */
#include<stdio.h>
#include<string.h>

#define MAXLEN 22 //最大数值20。多出来首行首列和最后一列的barrier障碍标记
#define NOZERO 1

int main(){
  int arr[22][22] = { 0 };
  int num = 1;
  int i;
  int j;
  int value;
  // while (~scanf_s("%d", &value, sizeof(value))) {
  while (scanf("%d", &value)) {
    for (i = 0; i < MAXLEN; i++) {// 首行首列置一，这一行是多出来的标记。栅栏barrier.
      arr[i][0] = NOZERO;
      arr[0][i] = NOZERO;
    }
    arr[num][value + 1] = NOZERO; //标记第一行的终点。barrier
    // (value * value - value) / 2 + value 三角数定理
    // for (i = 1, j = 0; num <= (value * value - value) / 2 + value;) {
    for (i = 1, j = 0; num <= (value * value + value) / 2 ;) {
      // 为0的，表示没有写过的位置
      while (!arr[i][j + 1]) {   // 横向
        arr[i][++j] = num++;
      }
      while (!arr[i + 1][j - 1]) { // 斜向
        arr[++i][--j] = num++;  // 行数+，列数-
      }
      while (!arr[i - 1][j]) {  // 竖向，反向向上
        arr[--i][j] = num++;
      }
    }
    for (i = 1; i <= value; i++) {
      for (j = 1; j <= value + 1 - i; j++)
        printf("%4d", arr[i][j]);
      printf("\n");
    }
    memset(arr, 0, sizeof(arr));  // reset
    num = 1;
  }
  return 0;
}


