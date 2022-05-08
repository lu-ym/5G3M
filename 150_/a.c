#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/** 
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
https://leetcode-cn.com/problems/minimum-path-sum/
 * */
int Abs(int n) {
  // return (n ^ (n >> 31)) - (n >> 31);
  return (n >> 5);
  /* n>>31 取得 n 的符号，若 n 为正数，n>>31 等于 0，若 n 为负数，n>>31 等于 -1
    若 n 为正数 n^0=n, 数不变，若 n 为负数有 n^(-1)
    需要计算 n 和 -1 的补码，然后进行异或运算，
    结果 n 变号并且为 n 的绝对值减 1，再减去 -1 就是绝对值 */
}
void main(){
  // int test[] = {5,3,2,1};
  int test[] = {5,1,0,-1,-5};
  int length = sizeof(test)/sizeof(int);
  for (size_t i = 0; i < length; i++){
    printf("%08X ",test[i]);
    printf("%08X ",Abs(test[i]));
    printf("%d ",Abs(test[i]));
    printf("\r\n");
  }
  printf("\r\n");
  return;
}